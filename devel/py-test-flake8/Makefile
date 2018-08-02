# $NetBSD: Makefile,v 1.5 2018/08/02 15:36:55 adam Exp $

DISTNAME=	pytest-flake8-1.0.2
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
