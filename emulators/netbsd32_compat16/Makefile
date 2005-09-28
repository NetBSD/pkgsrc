# $NetBSD: Makefile,v 1.11 2005/09/28 20:52:21 rillig Exp $
#

.if ${MACHINE_ARCH} == "sparc64"
MACHINE32_ARCH=	sparc
.elif ${MACHINE_ARCH} == "x86_64"
MACHINE32_ARCH=	i386
.else
MACHINE32_ARCH=	${MACHINE_ARCH}
.endif

.if ${MACHINE32_ARCH} == "sparc"
DISTNAME=		compat16-${MACHINE32_ARCH}
.else
DISTNAME=		compat16-${MACHINE32_ARCH}-1.6.0
.endif
PKGNAME=		netbsd32_compat16-1.0
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/Releases/formal-1.6/index.html
COMMENT=		32-bit shared libraries for NetBSD 1.6 (and earlier) compatibility

CONFLICTS=		netbsd32_compat15-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-sparc64
ONLY_FOR_PLATFORM+=	NetBSD-[2-9]*-x86_64

NO_MTREE=		yes
NO_BUILD=		yes
SHLIB_HANDLING=		NO
USE_PKGINSTALL= 	YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

FILES_SUBST+=		COMPAT_EMULSUBDIR=${COMPAT_EMULSUBDIR}
FILES_SUBST+=		MACHINE_ARCH=${MACHINE_ARCH}
FILES_SUBST+=		OBJECT_FMT=${OBJECT_FMT}
FILES_SUBST+=		LDCONFIG=${LDCONFIG}

.include "../../mk/bsd.prefs.mk"

EMULSUBDIR=		emul/netbsd32
COMPAT_LIBDIR=		${PREFIX}/${EMULSUBDIR}/usr/lib
COMPAT_LIBEXECDIR=	${PREFIX}/${EMULSUBDIR}/usr/libexec
COMPAT_XLIBDIR=		${PREFIX}/${EMULSUBDIR}/usr/X11R6/lib

PLIST_SUBST+=		COMPAT_EMULSUBDIR=${EMULSUBDIR}

# XXX using pax to copy symlinks properly.
do-install:
	${INSTALL_DATA_DIR} ${COMPAT_LIBDIR}
	${INSTALL_DATA_DIR} ${COMPAT_XLIBDIR}
	${INSTALL_DATA_DIR} ${COMPAT_LIBEXECDIR}
	(cd ${WRKDIR}/usr/lib; pax -rwv lib*.so* i18n/lib*.so* ${COMPAT_LIBDIR})
	(cd ${WRKDIR}/usr/X11R6/lib; pax -rwv lib*.so* ${COMPAT_XLIBDIR})
	(cd ${WRKDIR}/usr/libexec; pax -rwv ld.*so ${COMPAT_LIBEXECDIR})
	${CHOWN} ${ROOT_USER}:${ROOT_GROUP} \
		${COMPAT_LIBDIR}/lib*.so* ${COMPAT_LIBDIR}/i18n/lib*.so* \
		${COMPAT_XLIBDIR}/lib*.so* ${COMPAT_LIBEXECDIR}/ld.*so
	${CHMOD} 555 ${COMPAT_LIBDIR}/lib*.so* ${COMPAT_LIBDIR}/i18n/lib*.so* \
		  ${COMPAT_XLIBDIR}/lib*.so* ${COMPAT_LIBEXECDIR}/ld.*so

.include "../../mk/bsd.pkg.mk"
