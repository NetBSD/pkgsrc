# $NetBSD: bsd.buildlink.mk,v 1.39 2001/10/05 02:31:18 jlam Exp $
#
# This Makefile fragment is included by package buildlink.mk files.  This
# file does the following things:
#
# (1) Defines a macro target, _BUILDLINK_USE, that symlinks package files
#     into a new hierarchy under ${BUILDLINK_DIR};
# (2) Defines BUILDLINK_CPPFLAGS and BUILDLINK_LDFLAGS to be the flags
#     needed to find the buildlink include files and buildlink libraries,
#     respectively.
# (3) Prepends ${BUILDLINK_CPPFLAGS} to CPPFLAGS, CFLAGS, and CXXFLAGS;
# (4) Prepends ${BUILDLINK_LDFLAGS} to LDFLAGS.
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
#				targets to be invoked; this is just usually	#				<pkgname>-buildlink and possibly
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

.if !defined(BUILDLINK_CPPFLAGS) || !defined(BUILDLINK_LDFLAGS)
BUILDLINK_CPPFLAGS=	-I${BUILDLINK_DIR}/include
BUILDLINK_LDFLAGS=	-L${BUILDLINK_DIR}/lib

CFLAGS:=		${BUILDLINK_CPPFLAGS} ${CFLAGS}
CXXFLAGS:=		${BUILDLINK_CPPFLAGS} ${CXXFLAGS}
CPPFLAGS:=		${BUILDLINK_CPPFLAGS} ${CPPFLAGS}
LDFLAGS:=		${BUILDLINK_LDFLAGS} ${LDFLAGS}

CONFIGURE_ENV+=		BUILDLINK_DIR="${BUILDLINK_DIR}"
CONFIGURE_ENV+=		BUILDLINK_CPPFLAGS="${BUILDLINK_CPPFLAGS}"
CONFIGURE_ENV+=		BUILDLINK_LDFLAGS="${BUILDLINK_LDFLAGS}"

MAKE_ENV+=		BUILDLINK_DIR="${BUILDLINK_DIR}"
MAKE_ENV+=		BUILDLINK_CPPFLAGS="${BUILDLINK_CPPFLAGS}"
MAKE_ENV+=		BUILDLINK_LDFLAGS="${BUILDLINK_LDFLAGS}"
.endif

# Filter out libtool archives from the list of file to link into
# ${BUILDLINK_DIR}.
#
_LIBTOOL_ARCHIVE_FILTER=						\
	${SED}	-e 's|[^[:blank:]]*lib/[^[:blank:]]*.la$$||g'		\
		-e 's|[^[:blank:]]*lib/[^[:blank:]]*.la[[:blank:]]||g'

_BUILDLINK_USE: .USE
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.${.TARGET:S/-buildlink//}_buildlink_done; \
	if [ ! -f $${cookie} ]; then					\
		${ECHO_MSG} "Linking ${.TARGET:S/-buildlink//} files into ${BUILDLINK_DIR}."; \
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
BUILDLINK_CONFIG_WRAPPER_POST_SED+=					\
	-e "s|-I${LOCALBASE}/|-I${BUILDLINK_DIR}/|g"			\
	-e "s|-L${LOCALBASE}/|-L${BUILDLINK_DIR}/|g"

_BUILDLINK_CONFIG_WRAPPER_USE: .USE
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.${.TARGET:S/-buildlink-config-wrapper//}_buildlink_config_wrapper_done; \
	if [ ! -f $${cookie} ]; then					\
		${ECHO_MSG} "Creating wrapper script ${BUILDLINK_CONFIG_WRAPPER.${.TARGET:S/-buildlink-config-wrapper//}}."; \
		${MKDIR} ${BUILDLINK_CONFIG_WRAPPER.${.TARGET:S/-buildlink-config-wrapper//}:H}; \
		(${ECHO} '#!/bin/sh';					\
		${ECHO} '';						\
		${ECHO} '${ECHO} "`${BUILDLINK_CONFIG.${.TARGET:S/-buildlink-config-wrapper//}} $$*`" | ${SED} \'; \
		${ECHO} '	${BUILDLINK_CONFIG_WRAPPER_SED} \';	\
		${ECHO} '	${BUILDLINK_CONFIG_WRAPPER_POST_SED} \'; \
		) > ${BUILDLINK_CONFIG_WRAPPER.${.TARGET:S/-buildlink-config-wrapper//}}; \
		${CHMOD} +x ${BUILDLINK_CONFIG_WRAPPER.${.TARGET:S/-buildlink-config-wrapper//}}; \
		${ECHO} ${BUILDLINK_CONFIG.${.TARGET:S/-buildlink-config-wrapper//}} >> $${cookie}; \
	fi

.include "../../mk/bsd.prefs.mk"

_CHECK_IS_TEXT_FILE=	${FILE_CMD} $${file} | ${GREP} "text" >/dev/null 2>&1

# _REPLACE_LIBNAMES_SCRIPT runs sed with ${REPLACE_LIBNAMES_SED} as the
# substitution expression on the files specified in $${replace_files}.
# The following variables need to be predefined:
#
#	cookie			cookie created after this command is run
#	replace_files		files on which to run the substitution
#	message			message to display
#
_REPLACE_LIBNAMES_SCRIPT=						\
	${MKDIR} ${BUILDLINK_DIR};					\
	if [ -n "$${replace_files}" -a -n "${REPLACE_LIBNAMES_SED:Q}" ]; then \
		${ECHO_MSG} "$${message}";				\
		cd ${WRKSRC};						\
		for file in $${replace_files}; do			\
			if ${_CHECK_IS_TEXT_FILE}; then			\
				${ECHO_MSG} "	$${file}";		\
				${SED}	${REPLACE_LIBNAMES_SED}		\
					$${file} > $${file}.fixed;	\
				if [ -x $${file} ]; then		\
					${CHMOD} +x $${file}.fixed;	\
				fi;					\
				${MV} -f $${file}.fixed $${file};	\
				${ECHO} $${file} >> $${cookie};		\
			fi;						\
		done;							\
	fi

MAKEFILE_PATTERNS+=	Makefile
MAKEFILE_PATTERNS+=	Makeconf
MAKEFILE_PATTERNS+=	*.mk

.if (${OBJECT_FMT} == "a.out")
REPLACE_LIBNAME_PATTERNS+=	${MAKEFILE_PATTERNS}
REPLACE_LIBNAME_PATTERNS_FIND=	\
	${REPLACE_LIBNAME_PATTERNS:S/$/!/:S/^/-or -name !/:S/!/"/g:S/-or//1}

REPLACE_LIBNAMES+=	\
	`cd ${WRKSRC}; ${FIND} . ${REPLACE_LIBNAME_PATTERNS_FIND} | ${SED} -e 's|^\./||' | ${SORT}`
.endif

.if defined(REPLACE_LIBNAMES) || defined(REPLACE_LIBNAME_PATTERNS)
.if defined(HAS_CONFIGURE) || defined(GNU_CONFIGURE)
pre-configure: replace-libnames-configure

# Fix linking on a.out platforms in configure scripts by changing library
# references to the true library names.
#
replace-libnames-configure:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.replace_libnames_configure_done;	\
	if [ ! -f $${cookie} ]; then					\
		replace_files="${CONFIGURE_SCRIPT}";			\
		message="Fixing library name references in configure scripts:"; \
		${_REPLACE_LIBNAMES_SCRIPT};				\
	fi
.endif	# HAS_CONFIGURE

post-configure: replace-libnames-makefiles

# Fix linking on a.out platforms by changing library references in Makefiles
# to the true library names.
#
replace-libnames-makefiles:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.replace_libnames_makefiles_done;	\
	if [ ! -f $${cookie} ]; then					\
		replace_files="${REPLACE_LIBNAMES}";			\
		message="Fixing library name references in Makefiles:";	\
		${_REPLACE_LIBNAMES_SCRIPT};				\
	fi
.endif	# REPLACE_LIBNAMES

REPLACE_RPATH_PATTERNS+=	${MAKEFILE_PATTERNS}
REPLACE_RPATH_PATTERNS_FIND=	\
	${REPLACE_RPATH_PATTERNS:S/$/!/:S/^/-or -name !/:S/!/"/g:S/-or//1}

REPLACE_RPATH+=	\
	`cd ${WRKSRC}; ${FIND} . ${REPLACE_RPATH_PATTERNS_FIND} | ${SED} -e 's|^\./||' | ${SORT}`

REPLACE_RPATH_SED+=	\
	-e "s|-R${BUILDLINK_DIR}/|-R${LOCALBASE}/|g"

post-configure: replace-rpath

replace-rpath:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.replace_rpath_done;			\
	if [ ! -f $${cookie} ]; then					\
		${MKDIR} ${BUILDLINK_DIR};				\
		replace_files="${REPLACE_RPATH}";			\
		if [ -n "$${replace_files}" ]; then			\
			${ECHO_MSG} "Removing rpath references to buildlink directories:"; \
			cd ${WRKSRC};					\
			for file in $${replace_files}; do		\
				if ${_CHECK_IS_TEXT_FILE}; then		\
					${ECHO_MSG} "	$${file}";	\
					${SED}	${REPLACE_RPATH_SED}	\
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

REPLACE_BUILDLINK_PATTERNS+=	*.lai
REPLACE_BUILDLINK_PATTERNS+=	*-config
REPLACE_BUILDLINK_PATTERNS+=	*Conf.sh
REPLACE_BUILDLINK_PATTERNS+=	*.pc
REPLACE_BUILDLINK_PATTERNS_FIND=	\
	${REPLACE_BUILDLINK_PATTERNS:S/$/!/:S/^/-or -name !/:S/!/"/g:S/-or//1}

REPLACE_BUILDLINK+=	\
	`cd ${WRKSRC}; ${FIND} . ${REPLACE_BUILDLINK_PATTERNS_FIND} | ${SED} -e 's|^\./||' | ${SORT}`

.if defined(REPLACE_BUILDLINK)
post-build: replace-buildlink

REPLACE_BUILDLINK_SED?=		# empty
REPLACE_BUILDLINK_POST_SED+=						\
	-e "s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g"			\
	-e "s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g"

REPLACE_BUILDLINK_POST_SED+=	${REPLACE_RPATH_SED}

# Fix files by removing buildlink directory references and library names.
replace-buildlink:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.replace_buildlink_done;		\
	if [ ! -f $${cookie} ]; then					\
		${MKDIR} ${BUILDLINK_DIR};				\
		replace_files="${REPLACE_BUILDLINK}";			\
		if [ -n "$${replace_files}" ]; then			\
			${ECHO_MSG} "Fixing directory references and library names:"; \
			cd ${WRKSRC};					\
			for file in $${replace_files}; do		\
				if ${_CHECK_IS_TEXT_FILE}; then		\
					${ECHO_MSG} "	$${file}";	\
					${SED}	${REPLACE_BUILDLINK_SED} \
						${REPLACE_BUILDLINK_POST_SED} \
						${REPLACE_LIBNAMES_SED}	\
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
.endif	# REPLACE_BUILDLINK

.endif	# _BSD_BUILDLINK_MK
