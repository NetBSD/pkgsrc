# $NetBSD: inplace.mk,v 1.1 2004/08/13 22:34:28 jlam Exp $
#
# This Makefile fragment builds a working copy of libnbcompat inside
# ${WRKDIR} and adds the appropriate paths to CPPFLAGS and LDFLAGS.
# This can be used in place of libnbcompat/buildlink3.mk where it is
# included by a bootstrap package Makefile.

LIBNBCOMPAT_FILESDIR=	${.CURDIR}/../../pkgtools/libnbcompat/files
LIBNBCOMPAT_SRCDIR=	${WRKDIR}/libnbcompat

CPPFLAGS+=		-I${LIBNBCOMPAT_SRCDIR}
LDFLAGS+=		-L${LIBNBCOMPAT_SRCDIR}
LIBS+=			-lnbcompat

do-extract: libnbcompat-extract
libnbcompat-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${CP} -Rp ${LIBNBCOMPAT_FILESDIR} ${LIBNBCOMPAT_SRCDIR}

pre-configure: libnbcompat-build
libnbcompat-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${LIBNBCOMPAT_SRCDIR} && ${SETENV}				\
		AWK="${AWK}" CC="${CC}" CFLAGS="${CFLAGS:M*}"		\
		CPPFLAGS="${CPPFLAGS:M*}"				\
		${CONFIGURE_ENV:NLIBS=*} ${CONFIG_SHELL}		\
		${CONFIGURE_SCRIPT} && ${MAKE_PROGRAM}
