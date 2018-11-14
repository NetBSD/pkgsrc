# $NetBSD: Makefile,v 1.7 2018/11/14 22:21:45 kleink Exp $

DISTNAME=	RawTherapee-5.3
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Beep6581/}
GITHUB_PROJECT=	RawTherapee
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://rawtherapee.com/
COMMENT=	Powerful cross-platform raw photo processing program
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DPKGMANDIR=${PKGMANDIR}

# ReleaseInfo.cmake must exist or it will try to use git(1) to regen it.
pre-configure:
	touch ${WRKSRC}/ReleaseInfo.cmake

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/lensfun/buildlink3.mk"
.include "../../graphics/libiptcdata/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
