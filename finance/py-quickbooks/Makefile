# $NetBSD: Makefile,v 1.7 2022/07/08 14:04:09 wiz Exp $

DISTNAME=	python-quickbooks-0.6.0
PKGNAME=	${PYPKGPREFIX}-quickbooks-0.6.0
PKGREVISION=	1
CATEGORIES=	python finance
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-quickbooks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sidecars/python-quickbooks
COMMENT=	Python library for accessing the Quickbooks API
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-rauth>=0.7.3:../../devel/py-rauth

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
