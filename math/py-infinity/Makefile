# $NetBSD: Makefile,v 1.4 2017/09/27 20:21:54 adam Exp $

DISTNAME=	infinity-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/infinity/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/infinity
COMMENT=	All-in-one infinity value for Python
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8>=2.4.0:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.2:../../devel/py-isort
BUILD_DEPENDS+=	${PYPKGPREFIX}-pygments>=1.2:../../textproc/py-pygments
BUILD_DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=2.2.3:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
