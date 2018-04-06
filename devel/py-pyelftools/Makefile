# $NetBSD: Makefile,v 1.2 2018/04/06 07:08:26 adam Exp $

DISTNAME=	pyelftools-0.24
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyelftools/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/eliben/pyelftools
COMMENT=	Library for analyzing ELF files and DWARF debugging information
LICENSE=	public-domain

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} readelf.py readelf-${PYVERSSUFFIX}.py || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test/run_all_unittests.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
