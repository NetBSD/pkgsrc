# $NetBSD: Makefile,v 1.23 2003/08/30 18:53:07 jlam Exp $
#

DISTNAME=		compat12-${MACHINE_ARCH}
PKGNAME=		compat12-1.2.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/Releases/formal-1.2/index.html
COMMENT=		Shared libraries for NetBSD 1.2 (and earlier) compatibility

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-m68k NetBSD-*-ns32k \
			NetBSD-*-sparc

NO_BUILD=		# defined
NO_MTREE=		# defined
SHLIB_HANDLING=		NO
USE_PKGINSTALL=		YES

FILES_SUBST+=		COMPAT_LIBDIR=${COMPAT_LIBDIR}
FILES_SUBST+=		MACHINE_ARCH=${MACHINE_ARCH}
FILES_SUBST+=		OBJECT_FMT=${OBJECT_FMT}
FILES_SUBST+=		LDCONFIG=${LDCONFIG}

.include "../../mk/bsd.prefs.mk"

# This installs in /usr (or /emul/aout/usr) to avoid dynamic linker annoyances
.if ${OBJECT_FMT} == "ELF" && \
    (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "sparc")
EMULSUBDIR=		emul/aout
COMPAT_LIBDIR=		${EMULSUBDIR}/usr/lib
.else
LOCALBASE=		/usr
COMPAT_LIBDIR=		lib
.endif

PLIST_SUBST+=		COMPAT_LIBDIR=${COMPAT_LIBDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/lib*.so* ${PREFIX}/${COMPAT_LIBDIR}

.include "../../mk/bsd.pkg.mk"
