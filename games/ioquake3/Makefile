# $NetBSD: Makefile,v 1.10 2020/03/08 16:49:39 wiz Exp $
#

DISTNAME=	ioquake3-1.36.20200125
PKGREVISION=	1
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

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/ioquake3
	cd ${WRKSRC} && ${GMAKE} copyfiles COPYDIR=${DESTDIR}${PREFIX}/lib/ioquake3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${MACHINE_CPU:U} == "arm"
QUAKE_ARCH!=	uname -m
.elif ${OPSYS} == "NetBSD" && ${MACHINE_CPU:U} == "aarch64"
QUAKE_ARCH=	${MACHINE_CPU}
.else
QUAKE_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUBST+=	QUAKE_ARCH=${QUAKE_ARCH:Q}

# recursive error after: VM_CompileX86: mprotect failed
NOT_PAX_MPROTECT_SAFE+=	lib/ioquake3/ioq3ded.${QUAKE_ARCH}
NOT_PAX_MPROTECT_SAFE+=	lib/ioquake3/ioquake3.${QUAKE_ARCH}

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
