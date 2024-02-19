# $NetBSD: Makefile,v 1.30 2024/02/19 04:18:49 pin Exp $

VERSION=	1.2.0
DISTNAME=	FeatherNotes-V${VERSION}
PKGNAME=	feathernotes-${VERSION}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsujan/}
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/tsujan/FeatherNotes/
COMMENT=	Lightweight Qt6 hierarchical notes-manager
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/FeatherNotes-${VERSION}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
