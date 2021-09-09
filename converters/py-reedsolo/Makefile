# $NetBSD: Makefile,v 1.1 2021/09/09 07:31:02 adam Exp $

DISTNAME=	reedsolo-1.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES+=	${MASTER_SITE_PYPI:=r/reedsolo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tomerfiliba/reedsolomon
COMMENT=	Pure-Python Reed Solomon encoder/decoder
LICENSE=	mit

#TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

#PYTHON_VERSIONS_INCOMPATIBLE=	27

#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
