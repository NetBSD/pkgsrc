# $NetBSD: Makefile,v 1.8 2023/07/01 08:37:33 wiz Exp $

DISTNAME=	soundfile-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/soundfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pysoundfile.readthedocs.io/
COMMENT=	Audio library based on libsndfile, CFFI and NumPy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
