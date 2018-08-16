# $NetBSD: Makefile,v 1.40 2018/08/16 18:54:29 adam Exp $
#

PKGNAME=	libkface-4.13.0
PKGREVISION=	11
DISTNAME=	digikam-4.13.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.digikam.org/
COMMENT=	LibFace Library interface for KDE
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
CMAKE_ARGS+=		-DENABLE_OPENCV3:BOOL=ON

PKGCONFIG_OVERRIDE+=	libkface.pc.cmake

WRKSRC=			${WRKDIR}/${DISTNAME}/extra/libkface

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../graphics/opencv-contrib-face/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
