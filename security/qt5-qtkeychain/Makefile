# $NetBSD: Makefile,v 1.5 2020/04/12 08:29:11 adam Exp $

QTKEYCHAINVER=	0.9.1
DISTNAME=	qtkeychain-${QTKEYCHAINVER}
PKGNAME=	qt5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	-https://github.com/frankosterfeld/qtkeychain/archive/v${QTKEYCHAINVER}.tar.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/frankosterfeld/qtkeychain/
COMMENT=	Platform-independent Qt API for storing passwords securely
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
