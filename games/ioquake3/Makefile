# $NetBSD: Makefile,v 1.6 2016/07/16 00:10:33 markd Exp $
#

DISTNAME=	ioquake3-1.36
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://ioquake3.org/files/1.36/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ioquake3.org/
COMMENT=	Open source Quake 3 distribution

USE_TOOLS+=	gmake
BUILD_TARGET=	release

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/ioquake3
	cd ${WRKSRC} && ${GMAKE} copyfiles COPYDIR=${DESTDIR}${PREFIX}/lib/ioquake3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${MACHINE_CPU:U} == "arm"
QUAKE_ARCH!=	uname -m
.else
QUAKE_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUBST+=	QUAKE_ARCH=${QUAKE_ARCH:Q}

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
