# $NetBSD: Makefile,v 1.22 2005/09/28 20:52:20 rillig Exp $
#

DISTNAME=		compat13-${MACHINE_ARCH}${PKGMINOR}
PKGNAME=		compat13-1.3.3
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/Releases/formal-1.3/index.html
COMMENT=		Shared libraries for NetBSD 1.3 (and earlier) compatibility

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm NetBSD-*-arm32	\
			NetBSD-*-i386 NetBSD-*-m68k NetBSD-*-mipsel	\
			NetBSD-*-ns32k NetBSD-*-sparc
NOT_FOR_PLATFORM=	NetBSD-1.3*-*

NO_MTREE=		yes
NO_BUILD=		yes
SHLIB_HANDLING=		NO
USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

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
.elif ${OPSYS} == "NetBSD"
LOCALBASE=		/usr
COMPAT_LIBDIR=		lib
.endif

.if ${MACHINE_ARCH} == "alpha"
PKGMINOR=	nb1
.else
PKGMINOR=
.endif

PLIST_SUBST+=		COMPAT_LIBDIR=${COMPAT_LIBDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/lib*.so* ${PREFIX}/${COMPAT_LIBDIR}

.include "../../mk/bsd.pkg.mk"
