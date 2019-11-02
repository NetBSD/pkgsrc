# $NetBSD: Makefile,v 1.4 2019/11/02 16:08:48 rillig Exp $

DISTNAME=	python-quickbooks-0.6.0
PKGNAME=	${PYPKGPREFIX}-quickbooks-0.6.0
CATEGORIES=	python finance
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-quickbooks/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	https://github.com/sidecars/python-quickbooks
COMMENT=	Python library for accessing the Quickbooks API
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-rauth>=0.7.3:../../devel/py-rauth

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
