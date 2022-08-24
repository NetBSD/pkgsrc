# $NetBSD: Makefile,v 1.10 2022/08/24 08:41:08 wiz Exp $

DISTNAME=	Logbook-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=L/Logbook/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://logbook.readthedocs.io/
COMMENT=	Logging replacement for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-brotlipy-[0-9]*:../../archivers/py-brotlipy

PYTHON_VERSIONED_DEPENDENCIES+=	test:test test-cov:test

pre-build:
	cd ${WRKSRC} && cython-${PYVERSSUFFIX} logbook/_speedups.pyx

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
