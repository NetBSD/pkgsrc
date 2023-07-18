# $NetBSD: Makefile,v 1.2 2023/07/18 14:11:17 nia Exp $

DISTNAME=	p8-platform-2.1.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Pulse-Eight/}
GITHUB_PROJECT=	platform
GITHUB_TAG=	p8-platform-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Pulse-Eight/platform
COMMENT=	Platform support library used by libCEC
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11

USE_CXX_FEATURES+=	c++11

.include "../../mk/bsd.pkg.mk"
