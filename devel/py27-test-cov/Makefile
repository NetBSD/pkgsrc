# $NetBSD: Makefile,v 1.1 2022/08/24 08:34:46 wiz Exp $

DISTNAME=	pytest-cov-2.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-cov/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-cov
COMMENT=	Pytest plugin for measuring coverage
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-coverage>=5.2.1:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test4
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml


USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
