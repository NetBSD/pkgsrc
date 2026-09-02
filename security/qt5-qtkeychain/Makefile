# $NetBSD: Makefile,v 1.42 2026/09/02 19:04:21 wiz Exp $

DISTNAME=	qtkeychain-0.15.0
PKGNAME=	qt5-${DISTNAME}
PKGREVISION=	4
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
