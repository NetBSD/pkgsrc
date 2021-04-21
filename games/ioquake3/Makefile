# $NetBSD: Makefile,v 1.16 2021/04/21 13:24:41 adam Exp $
#

DISTNAME=	ioquake3-1.36.20200125
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ioquake/}
GITHUB_PROJECT=	ioq3
GITHUB_TAG=	daae32ddfdab2172a628072ed3ff7dd1fc1563fe

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ioquake3.org/
COMMENT=	Open source Quake 3 distribution
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
BUILD_TARGET=	release
INSTALL_TARGET=	copyfiles

MAKE_FLAGS+=	COPYDIR=${DESTDIR}${PREFIX}/lib/ioquake3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${MACHINE_CPU:U} == "arm"
QUAKE_ARCH!=	uname -m
.elif ${OPSYS} == "NetBSD" && ${MACHINE_CPU:U} == "aarch64"
QUAKE_ARCH=	${MACHINE_CPU}
.elif ${MACHINE_ARCH} == "i386"
QUAKE_ARCH=	x86
.else
QUAKE_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUBST+=	QUAKE_ARCH=${QUAKE_ARCH:Q}

# recursive error after: VM_CompileX86: mprotect failed
NOT_PAX_MPROTECT_SAFE+=	lib/ioquake3/ioq3ded.${QUAKE_ARCH}
NOT_PAX_MPROTECT_SAFE+=	lib/ioquake3/ioquake3.${QUAKE_ARCH}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man6
INSTALLATION_DIRS+=	lib/ioquake3

post-install:
.for prog in ioquake3 ioq3ded
	${LN} -sf ${DESTDIR}${PREFIX}/lib/ioquake3/${prog}.${QUAKE_ARCH} \
	    ${DESTDIR}${PREFIX}/bin/${prog}
	${INSTALL_MAN} ${FILESDIR}/${prog}.6 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
.endfor

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
