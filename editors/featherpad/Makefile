# $NetBSD: Makefile,v 1.49 2024/05/29 16:32:22 adam Exp $

VERSION=	1.5.1
DISTNAME=	FeatherPad-V${VERSION}
PKGNAME=	featherpad-${VERSION}
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsujan/}
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/tsujan/FeatherPad/
COMMENT=	Lightweight Qt6 plain-text editor
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/FeatherPad-${VERSION}
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
