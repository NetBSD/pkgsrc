# $NetBSD: Makefile,v 1.10 2005/09/28 20:52:20 rillig Exp $
#

DISTNAME=		compat14-crypto-${MACHINE_ARCH}-${VERSION}
PKGNAME=		compat14-crypto-${VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/Releases/formal-1.4/index.html
COMMENT=		Shared libraries for NetBSD 1.4 (and earlier) compatibility

VERSION=		1.4.3.1

CONFLICTS=		compat14-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-*-sparc NetBSD-*-i386
NOT_FOR_PLATFORM=	NetBSD-1.3*-* NetBSD-1.4*-*

CRYPTO=			YES

NO_MTREE=		yes
NO_BUILD=		yes
SHLIB_HANDLING=		NO
USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

FILES_SUBST+=		COMPAT_LIBDIR=${COMPAT_LIBDIR}
FILES_SUBST+=		COMPAT_XLIBDIR=${COMPAT_XLIBDIR}
FILES_SUBST+=		MACHINE_ARCH=${MACHINE_ARCH}
FILES_SUBST+=		OBJECT_FMT=${OBJECT_FMT}
FILES_SUBST+=		LDCONFIG=${LDCONFIG}

.include "../../mk/bsd.prefs.mk"

# This installs in /usr (or /emul/aout/usr) to avoid dynamic linker annoyances
.if ${OBJECT_FMT} == "ELF" && \
    (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "sparc")
EMULSUBDIR=		emul/aout
COMPAT_LIBDIR=		${EMULSUBDIR}/usr/lib
COMPAT_XLIBDIR=		${EMULSUBDIR}/usr/X11R6/lib
.elif ${OPSYS} == "NetBSD"
LOCALBASE=		/usr
COMPAT_LIBDIR=		lib
COMPAT_XLIBDIR=		X11R6/lib
.endif

PLIST_SUBST+=		COMPAT_LIBDIR=${COMPAT_LIBDIR} COMPAT_XLIBDIR=${COMPAT_XLIBDIR}

# note that the INSTALL_DATA for the lib*.so symlinks will copy the file, not the symlink.
# FIXME.
do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/lib/lib*.so* ${PREFIX}/${COMPAT_LIBDIR}
	if [ -d ${WRKDIR}/X11R6/lib ]; then \
		${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_XLIBDIR}; \
		${INSTALL_DATA} ${WRKDIR}/X11R6/lib/lib*.so* ${PREFIX}/${COMPAT_XLIBDIR}; \
	fi

.include "../../mk/bsd.pkg.mk"
