# $NetBSD: Makefile,v 1.3 2025/04/24 14:15:41 wiz Exp $

DISTNAME=	qtkeychain-0.15.0
PKGNAME=	qt6-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=frankosterfeld/}
GITHUB_PROJECT=	qtkeychain

HOMEPAGE=	https://github.com/frankosterfeld/qtkeychain/
COMMENT=	Platform-independent Qt API for storing passwords securely
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6:BOOL=ON

.include "../../devel/cmake/build.mk"

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
