# $NetBSD: Makefile,v 1.14 2022/11/10 08:19:36 adam Exp $

DISTNAME=	colorama-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_WHEEL:=colorama/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/tartley/colorama
COMMENT=	Cross-platform coloured terminal text
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
# as long as Python 2.7 is around
NO_BUILD=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
