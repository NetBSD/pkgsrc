# $NetBSD: Makefile,v 1.2 2017/07/24 16:30:20 adam Exp $

DISTNAME=	mando-0.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mando/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://mando.readthedocs.org/
COMMENT=	Create Python CLI apps with little to no effort at all
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
