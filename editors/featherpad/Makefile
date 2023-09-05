# $NetBSD: Makefile,v 1.42 2023/09/05 16:33:23 pin Exp $

VERSION=	1.4.1
DISTNAME=	FeatherPad-V${VERSION}
PKGNAME=	featherpad-${VERSION}
PKGREVISION=    1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsujan/}
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/tsujan/FeatherPad/
COMMENT=	Lightweight Qt5/Qt6 plain-text editor
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/FeatherPad-${VERSION}
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "options.mk"

.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
