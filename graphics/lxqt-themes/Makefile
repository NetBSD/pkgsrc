# $NetBSD: Makefile,v 1.18 2026/04/28 08:01:47 pin Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	lxqt-themes-2.4.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-themes/
COMMENT=	Themes, graphics and icons for LXQt
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config perl

TOOL_DEPENDS+=	lxqt-build-tools>=2.4.0:../../devel/lxqt-build-tools

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
