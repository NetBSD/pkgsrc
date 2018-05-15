# $NetBSD: Makefile,v 1.4 2018/05/15 06:37:49 adam Exp $

DISTNAME=	pytest-flake8-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-flake8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tholo/pytest-flake8
COMMENT=	Plugin plugin to check FLAKE8 requirements
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flake8>=3.5:../../devel/py-flake8
DEPENDS+=	${PYPKGPREFIX}-test>=3.2:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
