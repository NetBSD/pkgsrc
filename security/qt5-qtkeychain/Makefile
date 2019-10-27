# $NetBSD: Makefile,v 1.1 2019/10/27 18:20:00 bouyer Exp $

QTKEYCHAINVER=	0.9.1
DISTNAME=	qtkeychain-${QTKEYCHAINVER}
PKGNAME=	qt5-${DISTNAME}
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
