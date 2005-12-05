# $NetBSD: Makefile,v 1.27 2005/12/05 20:50:11 rillig Exp $
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

NO_BUILD=		yes
NO_MTREE=		yes
SHLIB_HANDLING=		NO
USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

FILES_SUBST+=		COMPAT_LIBDIR=${COMPAT_LIBDIR:Q}
FILES_SUBST+=		MACHINE_ARCH=${MACHINE_ARCH:Q}
FILES_SUBST+=		OBJECT_FMT=${OBJECT_FMT:Q}
FILES_SUBST+=		LDCONFIG=${LDCONFIG:Q}

.include "../../mk/bsd.prefs.mk"

# This installs in /usr (or /emul/aout/usr) to avoid dynamic linker annoyances
.if ${OBJECT_FMT} == "ELF" && \
    (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "sparc")
EMULSUBDIR=		emul/aout
COMPAT_LIBDIR=		${EMULSUBDIR}/usr/lib
.elif ${OPSYS} == "NetBSD"
LOCALBASE=		/usr
COMPAT_LIBDIR=		lib
.endif

PLIST_SUBST+=		COMPAT_LIBDIR=${COMPAT_LIBDIR:Q}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/lib*.so* ${PREFIX}/${COMPAT_LIBDIR}

.include "../../mk/bsd.pkg.mk"
