# $NetBSD: bsd.buildlink.mk,v 1.30 2001/08/22 04:29:55 jlam Exp $
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

_BUILDLINK_USE: .USE
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.${.TARGET:S/-buildlink//}_buildlink_done; \
	if [ ! -f $${cookie} ]; then					\
		${ECHO_MSG} "Linking ${.TARGET:S/-buildlink//} files into ${BUILDLINK_DIR}."; \
		${MKDIR} ${BUILDLINK_DIR};				\
		files="${BUILDLINK_FILES.${.TARGET:S/-buildlink//}:S/^/${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}\//g}"; \
		files="`${ECHO} $${files} | ${SED} -e 's|[^[:blank:]]*lib/[^[:blank:]]*.la$$||g' -e 's|[^[:blank:]]*lib/[^[:blank:]]*.la[[:blank:]]||g'`"; \
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

.if (${OBJECT_FMT} == "a.out")
REPLACE_LIBNAMES+=	\
	`${FIND} . -name "Makefile" -or -name "Makeconf" -or -name "*.mk" | ${SED} -e 's|\^\./||' | ${SORT}`
.endif

.if defined(REPLACE_LIBNAMES)
.if defined(HAS_CONFIGURE) || defined(GNU_CONFIGURE)
pre-configure: replace-libnames-1

# Fix linking on a.out platforms in configure scripts by changing library
# references to the true library names.
#
replace-libnames-1:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.replace_libnames_1_done;		\
	if [ ! -f $${cookie} ]; then					\
		${MKDIR} ${BUILDLINK_DIR};				\
		replace_libnames="${CONFIGURE_SCRIPT}";			\
		if [ -n "$${replace_libnames}" -a -n "${REPLACE_LIBNAMES_SED:Q}" ]; then \
			${ECHO_MSG} "Fixing library name references (part 1):"; \
			cd ${WRKSRC};					\
			for file in $${replace_libnames}; do		\
				${ECHO_MSG} "	$${file}";		\
				${MV} -f $${file} $${file}.fixme;	\
				${SED}	${REPLACE_LIBNAMES_SED}		\
					$${file}.fixme > $${file};	\
				if [ -x $${file}.fixme ]; then		\
					${CHMOD} +x $${file};		\
				fi;					\
				${RM} -f $${file}.fixme;		\
				${ECHO} $${file} >> $${cookie};		\
			done;						\
		fi;							\
	fi
.endif	# HAS_CONFIGURE

post-configure: replace-libnames-2

# Fix linking on a.out platforms by changing library references in Makefiles
# to the true library names.
#
replace-libnames-2:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.replace_libnames_2_done;		\
	if [ ! -f $${cookie} ]; then					\
		${MKDIR} ${BUILDLINK_DIR};				\
		replace_libnames="${REPLACE_LIBNAMES}";			\
		if [ -n "$${replace_libnames}" -a -n "${REPLACE_LIBNAMES_SED:Q}" ]; then \
			${ECHO_MSG} "Fixing library name references (part 2):"; \
			cd ${WRKSRC};					\
			for file in ${REPLACE_LIBNAMES}; do		\
				${ECHO_MSG} "	$${file}";		\
				${MV} -f $${file} $${file}.fixme;	\
				${SED}	${REPLACE_LIBNAMES_SED}		\
					$${file}.fixme > $${file};	\
				if [ -x $${file}.fixme ]; then		\
					${CHMOD} +x $${file};		\
				fi;					\
				${RM} -f $${file}.fixme;		\
				${ECHO} $${file} >> $${cookie};		\
			done;						\
		fi;							\
	fi
.endif	# REPLACE_LIBNAMES

# Note: This hack uses some libtool internals to correctly fix the references
# to ${BUILDLINK_DIR} into ${LOCALBASE}.
#
.if defined(USE_LIBTOOL)
REPLACE_BUILDLINK+=	\
	`${FIND} . -name "*.lai" | ${SED} -e 's|\^\./||' | ${SORT}`
.endif

.if defined(REPLACE_BUILDLINK)
post-build: replace-buildlink

REPLACE_BUILDLINK_SED?=		# empty
REPLACE_BUILDLINK_POST_SED+=						\
	-e "s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g"			\
	-e "s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g"

# Fix files by removing buildlink directory references.
replace-buildlink:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.replace_buildlink_done;		\
	if [ ! -f $${cookie} ]; then					\
		${MKDIR} ${BUILDLINK_DIR};				\
		replace_buildlink="${REPLACE_BUILDLINK}";		\
		if [ -n "$${replace_buildlink}" ]; then			\
			${ECHO_MSG} "Fixing directory references:";	\
			cd ${WRKSRC};					\
			for file in ${REPLACE_BUILDLINK}; do		\
				${ECHO_MSG} "	$${file}";		\
				${MV} -f $${file} $${file}.fixme;	\
				${SED}	${REPLACE_BUILDLINK_SED}	\
					${REPLACE_BUILDLINK_POST_SED}	\
					$${file}.fixme > $${file};	\
				if [ -x $${file}.fixme ]; then		\
					${CHMOD} +x $${file};		\
				fi;					\
				${RM} -f $${file}.fixme;		\
				${ECHO} $${file} >> $${cookie};		\
			done;						\
		fi;							\
	fi
.endif	# REPLACE_BUILDLINK

.endif	# _BSD_BUILDLINK_MK
