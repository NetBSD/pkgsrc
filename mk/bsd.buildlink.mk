# $NetBSD: bsd.buildlink.mk,v 1.51 2001/11/30 17:21:56 jlam Exp $
#
# This Makefile fragment is included by package buildlink.mk files.  This
# file does the following things:
#
# (1) Defines a macro target, _BUILDLINK_USE, that symlinks package files
#     into a new hierarchy under ${BUILDLINK_DIR};
# (2) Defines private variables _BUILDLINK_CPPFLAGS and _BUILDLINK_LDFLAGS
#     containing the magic flags needed to find the buildlink'ed headers
#     files and the buildlink'ed libraries, respectively.
# (3) Prepends ${_BUILDLINK_CPPFLAGS} to CPPFLAGS, CFLAGS, and CXXFLAGS;
# (4) Prepends ${_BUILDLINK_LDFLAGS} to LDFLAGS.
# (5) Defines a macro target, _BUILDLINK_CONFIG_WRAPPER_USE, that generates
#     a wrapper script around GTK+-style config scripts that replaces
#     -I${LOCALBASE}/... and -L${LOCALBASE}/... with references into
#     ${BUILDLINK_DIR}.
#
# The variables required to be defined prior to including this file are
# listed below.  <pkgname> refers to the name of the package and should be
# used consistently throughout the buildlink.mk file.
#
# BUILDLINK_PREFIX.<pkgname>	installation prefix of the package
#
# BUILDLINK_FILES.<pkgname>	files relative to ${BUILDLINK_PREFIX.<pkgname>}
#				to be symlinked into ${BUILDLINK_DIR};
#				libtool archive files are automatically
#				filtered out and not linked
#
# BUILDLINK_TARGETS		targets to be invoked during pre-configure;
#				the targets should be appended to this variable
#				using +=
#
# The variables that may optionally be defined are:
#
# BUILDLINK_TRANSFORM.<pkgname>	sed arguments used to transform the name of
#				the source filename into a destination
#				filename
#
# BUILDLINK_CONFIG.<pkgname>	absolute path to GTK+-style config script
#
# BUILDLINK_CONFIG_WRAPPER.<pkgname>
#				absolute path for generated wrapper script;
#				this should be under ${BUILDLINK_DIR}/bin
#
# Additional variables used by bsd.buildlink.mk that may be defined in
# either the package Makefile or in buildlink.mk files:
#
# REPLACE_BUILDLINK		space-separated list of files on which we
#				run ${SED} ${REPLACE_BUILDLINK_SED}
#
# REPLACE_BUILDLINK_PATTERNS	space-separated list of shell glob patterns
#				representing files on which we run ${SED}
#				${REPLACE_BUILDLINK_SED}
#
# REPLACE_BUILDLINK_SED		sed expression used primarily to replace
#				references to directories in ${BUILDLINK_DIR}
#				into directories in ${LOCALBASE} and
#				${X11PREFIX}
#
# REPLACE_LIBNAMES		space-separated list of files on which we
#				run ${SED} ${REPLACE_LIBNAMES_SED}
#
# REPLACE_LIBNAMES_PATTERNS	space-separated list of shell glob patterns
#				representing files on which we run ${SED}
#				${REPLACE_LIBNAMES_SED}
#
# REPLACE_LIBNAMES_SED		sed expression used primarily to replace
#				references to library names within
#				${BUILDLINK_DIR} into the true library names
#				from the base system.
#
# BUILDLINK_CONFIG_WRAPPER_SED	sed expression used primarily to replace
#				references to directories in ${LOCALBASE}
#				and ${X11PREFIX} into directories in
#				${BUILDLINK_DIR} or ${BUILDLINK_X11_DIR} in
#				the buildlink config wrapper scripts
#
# The targets required to be defined prior to including this file are
# listed below.
#
# pre-configure			this target should have as dependencies any
#				targets to be invoked; this is just usually
#				<pkgname>-buildlink and possibly
#				<pkgname>-buildlink-config-wrapper
#
# <pkgname>-buildlink		this target should just invoke the
#				_BUILDLINK_USE macro target defined in this
#				file
#
# The targets that may optionally be defined are:
#
# <pkgname>-buildlink-config-wrapper
#				this target should just invoke the
#				_BUILDLINK_CONFIG_WRAPPER_USE macro target
#				defined in this file
#
# Example package buildlink.mk file:
#
# .include "../../mk/bsd.buildlink.mk"
#
# BUILDLINK_DEPENDS.foo?=	foo>=1.0
# DEPENDS+=			${BUILDLINK_DEPENDS.foo}:../../category/foo
#
# EVAL_PREFIX+=			BUILDLINK_PREFIX.foo=foo
# BUILDLINK_FILES.foo=		include/foo.h
# BUILDLINK_FILES.foo+=		include/bar.h
# BUILDLINK_FILES.foo+=		lib/libfoo.*
#
# # We need the libraries to be called "libbar.*".
# BUILDLINK_TRANSFORM.foo=	-e "s|libfoo|libbar|g"
#
# BUILDLINK_TARGETS+=		foo-buildlink
#
# pre-configure: foo-buildlink
# foo-buildlink: _BUILDLINK_USE

.if !defined(_BSD_BUILDLINK_MK)
_BSD_BUILDLINK_MK=	# defined

BUILDLINK_DIR?=		${WRKDIR}/.buildlink

.if !defined(_BUILDLINK_CPPFLAGS) || !defined(_BUILDLINK_LDFLAGS)
_BUILDLINK_CPPFLAGS=	-I${BUILDLINK_DIR}/include
_BUILDLINK_LDFLAGS=	-L${BUILDLINK_DIR}/lib

CFLAGS:=		${_BUILDLINK_CPPFLAGS} ${CFLAGS}
CXXFLAGS:=		${_BUILDLINK_CPPFLAGS} ${CXXFLAGS}
CPPFLAGS:=		${_BUILDLINK_CPPFLAGS} ${CPPFLAGS}
LDFLAGS:=		${_BUILDLINK_LDFLAGS} ${LDFLAGS}

CONFIGURE_ENV+=		BUILDLINK_DIR="${BUILDLINK_DIR}"
CONFIGURE_ENV+=		BUILDLINK_CPPFLAGS="${_BUILDLINK_CPPFLAGS}"
CONFIGURE_ENV+=		BUILDLINK_LDFLAGS="${_BUILDLINK_LDFLAGS}"

MAKE_ENV+=		BUILDLINK_DIR="${BUILDLINK_DIR}"
MAKE_ENV+=		BUILDLINK_CPPFLAGS="${_BUILDLINK_CPPFLAGS}"
MAKE_ENV+=		BUILDLINK_LDFLAGS="${_BUILDLINK_LDFLAGS}"
.endif

ECHO_BUILDLINK_MSG?=	${ECHO_MSG} "=>"

# Filter out libtool archives from the list of file to link into
# ${BUILDLINK_DIR}.  Linking against a libtool archive causes the final
# installed locations of the libraries to be used, which defeats what
# buildlink tries to accomplish, so we avoid this when we can.
#
_LIBTOOL_ARCHIVE_FILTER=						\
	${SED}	-e 's|[^[:blank:]]*lib/[^[:blank:]]*.la$$||g'		\
		-e 's|[^[:blank:]]*lib/[^[:blank:]]*.la[[:blank:]]||g'

_BUILDLINK_USE: .USE
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.${.TARGET:S/-buildlink//}_buildlink_done; \
	if [ ! -f $${cookie} ]; then					\
		${ECHO_BUILDLINK_MSG} "Linking ${.TARGET:S/-buildlink//} files into ${BUILDLINK_DIR}."; \
		${MKDIR} ${BUILDLINK_DIR};				\
		files="${BUILDLINK_FILES.${.TARGET:S/-buildlink//}:S/^/${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}\//g}"; \
		files="`${ECHO} $${files} | ${_LIBTOOL_ARCHIVE_FILTER}`"; \
		for file in $${files}; do				\
			rel_file=`${ECHO} $${file} | ${SED} -e "s|${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}/||"` ; \
			if [ -z "${BUILDLINK_TRANSFORM.${.TARGET:S/-buildlink//}:Q}" ]; then \
				dest=${BUILDLINK_DIR}/$${rel_file};	\
			else						\
				dest=`${ECHO} ${BUILDLINK_DIR}/$${rel_file} | ${SED} ${BUILDLINK_TRANSFORM.${.TARGET:S/-buildlink//}}`; \
			fi;						\
			if [ -f $${file} ]; then			\
				dir=`${DIRNAME} $${dest}`;		\
				if [ ! -d $${dir} ]; then		\
					${MKDIR} $${dir};		\
				fi;					\
				${RM} -f $${dest};			\
				${LN} -sf $${file} $${dest};		\
				if [ -z "${BUILDLINK_TRANSFORM.${.TARGET:S/-buildlink//}:Q}" ]; then \
					${ECHO} $${file} >> $${cookie};	\
				else					\
					${ECHO} "$${file} -> $${dest}" >> $${cookie}; \
				fi;					\
			else						\
				${ECHO} "$${file}: not found" >> $${cookie}; \
			fi;						\
		done;							\
		${TOUCH} ${TOUCH_FLAGS} $${cookie};			\
	fi

# If a package uses only buildlink.mk files, then automatically set
# USE_CONFIG_WRAPPER to use config script wrappers for packages that
# have them.
#
.if defined(USE_BUILDLINK_ONLY)
USE_CONFIG_WRAPPER=	# defined
.endif

BUILDLINK_CONFIG_WRAPPER_SED?=		# empty
_BUILDLINK_CONFIG_WRAPPER_POST_SED+=					\
	-e "s|-I${LOCALBASE}/|-I${BUILDLINK_DIR}/|g"			\
	-e "s|-L${LOCALBASE}/|-L${BUILDLINK_DIR}/|g"

_BUILDLINK_CONFIG_WRAPPER_USE: .USE
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.${.TARGET:S/-buildlink-config-wrapper//}_buildlink_config_wrapper_done; \
	if [ ! -f $${cookie} ]; then					\
		${ECHO_BUILDLINK_MSG} "Creating wrapper script ${BUILDLINK_CONFIG_WRAPPER.${.TARGET:S/-buildlink-config-wrapper//}}."; \
		${MKDIR} ${BUILDLINK_CONFIG_WRAPPER.${.TARGET:S/-buildlink-config-wrapper//}:H}; \
		(${ECHO} '#!/bin/sh';					\
		${ECHO} '';						\
		${ECHO} '${ECHO} "`${BUILDLINK_CONFIG.${.TARGET:S/-buildlink-config-wrapper//}} $$*`" | ${SED} \'; \
		${ECHO} '	${BUILDLINK_CONFIG_WRAPPER_SED} \';	\
		${ECHO} '	${_BUILDLINK_CONFIG_WRAPPER_POST_SED} \'; \
		) > ${BUILDLINK_CONFIG_WRAPPER.${.TARGET:S/-buildlink-config-wrapper//}}; \
		${CHMOD} +x ${BUILDLINK_CONFIG_WRAPPER.${.TARGET:S/-buildlink-config-wrapper//}}; \
		${ECHO} ${BUILDLINK_CONFIG.${.TARGET:S/-buildlink-config-wrapper//}} >> $${cookie}; \
	fi

_CHECK_IS_TEXT_FILE=	${FILE_CMD} $${file} | ${GREP} "text" >/dev/null 2>&1

# _BUILDLINK_SUBST_USE is a make macro that executes code to do general text
# replacement in files.  The following variables are used:
#
# BUILDLINK_SUBST_MESSAGE.<package>	message to display, noting what is
#					being substituted
#					
# BUILDLINK_SUBST_FILES.<package>	files on which to run the substitution
#
# BUILDLINK_SUBST_SED.<package>		sed(1) substitution expression to run
#					on the specified files.
#
# The _BUILDLINK_SUBST_USE macro code will try to verify that a file is a text
# file before attempting any substitutions.
#
_BUILDLINK_SUBST_USE: .USE
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.${.TARGET:S/-buildlink-subst//:S/-/_/g}_buildlink_subst_done; \
	if [ ! -f $${cookie} ]; then					\
		${MKDIR} ${BUILDLINK_DIR};				\
		files="${BUILDLINK_SUBST_FILES.${.TARGET:S/-buildlink-subst//}}"; \
		if [ -n "$${files}" -a -n "${BUILDLINK_SUBST_SED.${.TARGET:S/-buildlink-subst//}:Q}" ]; then \
			${ECHO_BUILDLINK_MSG} ${BUILDLINK_SUBST_MESSAGE.${.TARGET:S/-buildlink-subst//}}; \
			cd ${WRKSRC};					\
			for file in $${files}; do			\
				if ${_CHECK_IS_TEXT_FILE}; then		\
					${SED}	${BUILDLINK_SUBST_SED.${.TARGET:S/-buildlink-subst//}} \
						$${file} > $${file}.fixed; \
					if [ -x $${file} ]; then	\
						${CHMOD} +x $${file}.fixed; \
					fi;				\
					${MV} -f $${file}.fixed $${file}; \
					${ECHO} $${file} >> $${cookie};	\
				fi;					\
			done;						\
		fi;							\
	fi

.include "../../mk/bsd.prefs.mk"

MAKEFILE_PATTERNS+=	${MAKEFILE:T}
MAKEFILE_PATTERNS+=	Makefile
MAKEFILE_PATTERNS+=	Makeconf
MAKEFILE_PATTERNS+=	*.mk

CONFIGURE_PATTERNS+=	${CONFIGURE_SCRIPT:T}
CONFIGURE_PATTERNS+=	configure
CONFIGURE_PATTERNS+=	configure.gnu
CONFIGURE_PATTERNS+=	Configure

.if (${OBJECT_FMT} == "a.out") || defined(BUILDLINK_AOUT_DEBUG)
REPLACE_LIBNAME_PATTERNS+=	${MAKEFILE_PATTERNS}
_REPLACE_LIBNAME_PATTERNS_FIND=	\
	\( ${REPLACE_LIBNAME_PATTERNS:S/$/!/:S/^/-o -name !/:S/!/"/g:S/-o//1} \)
_REPLACE_LIBNAME_CONFIGURE_PATTERNS_FIND=	\
	\( ${CONFIGURE_PATTERNS:S/$/!/:S/^/-o -name !/:S/!/"/g:S/-o//1} \)

REPLACE_LIBNAMES_CONFIGURE+=	\
	`cd ${WRKSRC}; ${FIND} . ${_REPLACE_LIBNAME_CONFIGURE_PATTERNS_FIND} -print | ${SED} -e 's|^\./||' | ${SORT}`

REPLACE_LIBNAMES+=	\
	`cd ${WRKSRC}; ${FIND} . ${_REPLACE_LIBNAME_PATTERNS_FIND} -print | ${SED} -e 's|^\./||' | ${SORT}`

.if defined(HAS_CONFIGURE) || defined(GNU_CONFIGURE)
_CONFIGURE_PREREQ+=	libnames-configure-buildlink-subst

# Fix linking on a.out platforms in configure scripts and in Makefiles by
# changing library references to the true library names.
#
BUILDLINK_SUBST_MESSAGE.libnames-configure=	\
	"Fixing library name references in configure scripts."
BUILDLINK_SUBST_FILES.libnames-configure=	${REPLACE_LIBNAMES_CONFIGURE}
BUILDLINK_SUBST_SED.libnames-configure=		${REPLACE_LIBNAMES_SED}

libnames-configure-buildlink-subst: _BUILDLINK_SUBST_USE
.endif

_CONFIGURE_POSTREQ+=	libnames-makefiles-buildlink-subst

# Fix linking on a.out platforms by changing library references in Makefiles
# to the true library names.
#
BUILDLINK_SUBST_MESSAGE.libnames-makefiles=	\
	"Fixing library name references in Makefiles."
BUILDLINK_SUBST_FILES.libnames-makefiles=	${REPLACE_LIBNAMES}
BUILDLINK_SUBST_SED.libnames-makefiles=		${REPLACE_LIBNAMES_SED}

libnames-makefiles-buildlink-subst: _BUILDLINK_SUBST_USE

.endif	# a.out || BUILDLINK_AOUT_DEBUG

REPLACE_RPATH_PATTERNS+=	${MAKEFILE_PATTERNS}
_REPLACE_RPATH_PATTERNS_FIND=	\
	\( ${REPLACE_RPATH_PATTERNS:S/$/!/:S/^/-o -name !/:S/!/"/g:S/-o//1} \)

REPLACE_RPATH+=	\
	`cd ${WRKSRC}; ${FIND} . ${_REPLACE_RPATH_PATTERNS_FIND} -print | ${SED} -e 's|^\./||' | ${SORT}`

REPLACE_RPATH_SED+=	\
	-e "s|-R[ 	]*${BUILDLINK_DIR}/|-R${LOCALBASE}/|g"

.if defined(_USE_RPATH) && (${_USE_RPATH} == "yes")
_CONFIGURE_POSTREQ+=	rpath-buildlink-subst

BUILDLINK_SUBST_MESSAGE.rpath=  \
	"Removing rpath references to buildlink directories."
BUILDLINK_SUBST_FILES.rpath=    ${REPLACE_RPATH}
BUILDLINK_SUBST_SED.rpath=      ${REPLACE_RPATH_SED}

rpath-buildlink-subst: _BUILDLINK_SUBST_USE
.endif

# Fix files by removing buildlink directory references and library names.
#
REPLACE_BUILDLINK_PATTERNS+=	*.lai
REPLACE_BUILDLINK_PATTERNS+=	*-config
REPLACE_BUILDLINK_PATTERNS+=	*Conf.sh
REPLACE_BUILDLINK_PATTERNS+=	*.pc
_REPLACE_BUILDLINK_PATTERNS_FIND=	\
	\( ${REPLACE_BUILDLINK_PATTERNS:S/$/!/:S/^/-o -name !/:S/!/"/g:S/-o//1} \)

REPLACE_BUILDLINK+=	\
	`cd ${WRKSRC}; ${FIND} . ${_REPLACE_BUILDLINK_PATTERNS_FIND} -print | ${SED} -e 's|^\./||' | ${SORT}`

post-build: unbuildlink-buildlink-subst

REPLACE_BUILDLINK_SED?=		# empty
_REPLACE_BUILDLINK_POST_SED+=						\
	-e "s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g"			\
	-e "s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g"

BUILDLINK_SUBST_MESSAGE.unbuildlink=	\
	"Fixing directory and library names in files-to-be-installed."
BUILDLINK_SUBST_FILES.unbuildlink=	${REPLACE_BUILDLINK}
BUILDLINK_SUBST_SED.unbuildlink=	${REPLACE_BUILDLINK_SED}	\
					${_REPLACE_BUILDLINK_POST_SED}	\
					${REPLACE_LIBNAMES_SED}		\
					${REPLACE_RPATH_SED}

unbuildlink-buildlink-subst: _BUILDLINK_SUBST_USE

.endif	# _BSD_BUILDLINK_MK
