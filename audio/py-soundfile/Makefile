# $NetBSD: Makefile,v 1.17 2026/06/07 04:57:31 adam Exp $

DISTNAME=	soundfile-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/soundfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bastibe/python-soundfile
COMMENT=	Audio library based on libsndfile, CFFI and NumPy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
