# $NetBSD: bsd.buildlink.mk,v 1.2 2001/06/11 03:20:48 jlam Exp $
#
# This Makefile fragment is included by package buildlink.mk files.  This
# file does 3 things:
#
# (1) Defines a macro target, _BUILDLINK_USE, that symlinks package files
#     into a new hierarchy under ${BUILDLINK_DIR};
# (2) Adds -I${BUILDLINK_DIR}/include to CPPFLAGS, CFLAGS, and CXXFLAGS;
# (3) Adds -L${BUILDLINK_DIR}/lib to LDFLAGS.
#
# By including buildlink.mk files before package-specific CFLAGS or LDFLAGS
# are defined, you can ensure that the buildlink directories are ahead of
# any package-specific directories in the compiler search paths.
#
# The variables required to be defined prior to including this file are
# listed below.  <pkgname> refers to the name of the package and should be
# used consistently throughout the buildlink.mk file.
#
# BUILDLINK_PREFIX.<pkgname>	installation prefix of the package
#
# BUILDLINK_FILES.<pkgname>	files relative to ${BUILDLINK_PREFIX.<pkgname>}
#				to be symlinked into ${BUILDLINK_DIR}
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
# The targets required to be defined prior to including this file are
# listed below.
#
# pre-configure			this target should have as dependencies any
#				targets to be invoked; this is just usually	#				<pkgname>-buildlink
#
# <pkgname>-buildlink		this target should just invoke the
#				_BUILDLINK_USE macro target defined in this
#				file
#
# Example package buildlink.mk file:
#
# BUILDLINK_PREFIX.foo=		${LOCALBASE}
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
#
# .include "../../mk/bsd.buildlink.mk"

.if !defined(_BSD_BUILDLINK_MK)
_BSD_BUILDLINK_MK=	# defined

BUILDLINK_DIR?=		${WRKDIR}/.buildlink

.if !defined(BUILDLINK_CPPFLAGS) || !defined(BUILDLINK_LDFLAGS)
BUILDLINK_CPPFLAGS=	-I${BUILDLINK_DIR}/include
BUILDLINK_LDFLAGS=	-L${BUILDLINK_DIR}/lib

CFLAGS+=		${BUILDLINK_CPPFLAGS}
CXXFLAGS+=		${BUILDLINK_CPPFLAGS}
CPPFLAGS+=		${BUILDLINK_CPPFLAGS}
LDFLAGS+=		${BUILDLINK_LDFLAGS}
.endif

_BUILDLINK_USE: .USE
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.${.TARGET:S/-buildlink//}_buildlink_done; \
	if [ ! -f $${cookie} ]; then					\
		${ECHO} "Linking ${.TARGET:S/-buildlink//} files into ${BUILDLINK_DIR}."; \
		for file in ${BUILDLINK_FILES.${.TARGET:S/-buildlink//}:S/^/${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}\//g}; do \
			if [ -z "${BUILDLINK_TRANSFORM.${.TARGET:S/-buildlink//}:Q}" ]; then \
				dest=${BUILDLINK_DIR}/$${file##${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}/}; \
			else						\
				dest=`${ECHO} ${BUILDLINK_DIR}/$${file##${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}/} | ${SED} ${BUILDLINK_TRANSFORM.${.TARGET:S/-buildlink//}}`; \
			fi;						\
			${MKDIR} $${dest%/*};				\
			if [ -f $${file} ]; then			\
				${RM} -f $${dest};			\
				${LN} -sf $${file} $${dest};		\
			fi;						\
		done;							\
		${TOUCH} ${TOUCH_FLAGS} $${cookie};			\
	fi

.endif	# _BSD_BUILDLINK_MK
