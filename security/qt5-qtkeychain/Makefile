# $NetBSD: Makefile,v 1.38 2025/08/17 08:57:12 wiz Exp $

DISTNAME=	qtkeychain-0.15.0
PKGNAME=	qt5-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=frankosterfeld/}
GITHUB_PROJECT=	qtkeychain
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/frankosterfeld/qtkeychain/
COMMENT=	Platform-independent Qt API for storing passwords securely
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
