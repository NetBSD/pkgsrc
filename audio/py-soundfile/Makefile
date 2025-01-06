# $NetBSD: Makefile,v 1.11 2025/01/06 11:40:13 adam Exp $

DISTNAME=	soundfile-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/soundfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bastibe/python-soundfile
COMMENT=	Audio library based on libsndfile, CFFI and NumPy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
