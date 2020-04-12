# $NetBSD: Makefile,v 1.60 2020/04/12 08:28:18 adam Exp $

DISTNAME=	Hydrogen-1.0.0-beta1
PKGNAME=	${DISTNAME:tl:C/-beta/.beta/}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=hydrogen-music/}
GITHUB_PROJECT=	Hydrogen
GITHUB_TAG=	${PKGVERSION_NOREV:C/.beta/-beta/}

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://hydrogen-music.org/
COMMENT=	Real time drum machine/sequencer
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:C/.beta/-beta/}

USE_LANGUAGES=	c gnu++11
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

# C++11
GCC_REQD+=	4.7

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
CMAKE_ARGS+=	-DWANT_OSS=ON
.else
CMAKE_ARGS+=	-DWANT_OSS=OFF
.endif

CMAKE_ARGS+=	-DWANT_CPPUNIT=OFF

# NetBSD libarchive is old?
CMAKE_ARGS+=	-DWANT_LIBARCHIVE=OFF
CMAKE_ARGS+=	-DWANT_LIBTAR=ON

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "options.mk"
.include "../../devel/libtar/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
