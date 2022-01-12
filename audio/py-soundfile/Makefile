# $NetBSD: Makefile,v 1.1 2022/01/12 21:26:38 wiz Exp $

DISTNAME=	SoundFile-0.10.3.post1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/post//}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SoundFile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pysoundfile.readthedocs.io/en/latest/
COMMENT=	Audio library based on libsndfile, CFFI and NumPy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
