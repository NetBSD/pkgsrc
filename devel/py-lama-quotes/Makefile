# $NetBSD: Makefile,v 1.1 2022/06/18 22:30:30 wiz Exp $

DISTNAME=	pylama_quotes-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylama-quotes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/pylama-quotes/
COMMENT=	Simple quote checker for pylama
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lama>=7.3.7:../../devel/py-lama

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
