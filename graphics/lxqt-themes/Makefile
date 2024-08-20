# $NetBSD: Makefile,v 1.13 2024/08/20 06:12:05 pin Exp $

DISTNAME=	lxqt-themes-2.0.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-themes/
COMMENT=	Themes, graphics and icons for LXQt
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	lxqt-build-tools>=2.0.0:../../devel/lxqt-build-tools

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
