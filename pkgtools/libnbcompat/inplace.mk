# $NetBSD: inplace.mk,v 1.4 2007/08/02 07:22:31 tron Exp $
#
# This Makefile fragment builds a working copy of libnbcompat inside
# ${WRKDIR} and adds the appropriate paths to CPPFLAGS and LDFLAGS.
# This can be used in place of libnbcompat/buildlink3.mk where it is
# included by a bootstrap package Makefile.

.include "../../mk/bsd.prefs.mk"

LIBNBCOMPAT_FILESDIR=	${.CURDIR}/../../pkgtools/libnbcompat/files
LIBNBCOMPAT_SRCDIR=	${WRKDIR}/libnbcompat

CPPFLAGS+=		-I${LIBNBCOMPAT_SRCDIR}
LDFLAGS+=		-L${LIBNBCOMPAT_SRCDIR}
LIBS+=			-lnbcompat

do-extract: libnbcompat-extract
libnbcompat-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${CP} -R ${LIBNBCOMPAT_FILESDIR} ${LIBNBCOMPAT_SRCDIR}

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
NBCOMPAT_CONFIGURE_ARGS+=	--build=${NATIVE_MACHINE_GNU_PLATFORM:Q}
.endif
NBCOMPAT_CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM:Q}

pre-configure: libnbcompat-build
libnbcompat-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${LIBNBCOMPAT_SRCDIR} && ${SETENV}				\
		AWK="${AWK}" CC="${CC}" CFLAGS="${CFLAGS:M*}"		\
		CPPFLAGS="${CPPFLAGS:M*}"				\
		${CONFIGURE_ENV:NLIBS=*} ${CONFIG_SHELL}		\
		${CONFIGURE_SCRIPT} ${NBCOMPAT_CONFIGURE_ARGS} &&	\
		${MAKE_PROGRAM}
