# $NetBSD: Makefile,v 1.13 2025/04/21 22:33:07 gutteridge Exp $

DISTNAME=	pyelftools-0.32
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyelftools/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/eliben/pyelftools
COMMENT=	Library for analyzing ELF files and DWARF debugging information
LICENSE=	public-domain

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} readelf.py readelf-${PYVERSSUFFIX}.py || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test/run_all_unittests.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
