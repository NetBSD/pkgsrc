# $NetBSD: Makefile,v 1.9 2024/03/23 07:21:47 adam Exp $

DISTNAME=	pyelftools-0.31
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyelftools/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/eliben/pyelftools
COMMENT=	Library for analyzing ELF files and DWARF debugging information
LICENSE=	public-domain

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=46.4.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} readelf.py readelf-${PYVERSSUFFIX}.py || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test/run_all_unittests.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
