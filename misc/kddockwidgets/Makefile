# $NetBSD: Makefile,v 1.4 2026/09/29 06:06:34 wiz Exp $

DISTNAME=	KDDockWidgets-2.4.1
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDAB/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KDAB/KDDockWidgets
COMMENT=	Dock Widgets Library by KDAB for Qt6
LICENSE=	modified-bsd AND gnu-gpl-v2 AND gnu-gpl-v3 AND mit

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings

.include "../../devel/cmake/build.mk"

.include "../../devel/spdlog/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
