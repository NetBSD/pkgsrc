# $NetBSD: Makefile,v 1.27 2020/11/05 09:08:59 ryoon Exp $

DISTNAME=	dspdfviewer-1.15.1
PKGREVISION=	24
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=dannyedel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://dspdfviewer.danny-edel.de/
COMMENT=	Dual-Screen PDF Viewer for latex-beamer
LICENSE=	gnu-gpl-v2

DEPENDS+=	qt5-qttools>=5.5.1:../../x11/qt5-qttools

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_CMAKE=		yes
CMAKE_ARGS+=		-DBuildTests=OFF
CONFIGURE_DIRS=		build
CMAKE_ARG_PATH=		..
BUILD_MAKE_FLAGS+=	VERBOSE=1

BUILDLINK_TRANSFORM+=	rm:-Werror

pre-configure:
	mkdir -p ${WRKSRC}/build

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler-qt5+=	poppler-qt5>=0.50.0
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
