# $NetBSD: Makefile,v 1.23 2025/11/24 12:52:23 adam Exp $

DISTNAME=	macholib-1.16.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/macholib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ronaldoussoren/macholib
COMMENT=	Mach-O header analysis and editing
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.17:../../graphics/py-altgraph

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	macholib/macho_dump.py
REPLACE_PYTHON+=	macholib/macho_find.py
REPLACE_PYTHON+=	macholib/macho_standalone.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} macho_dump macho_dump-${PYVERSSUFFIX} && \
	${MV} macho_find macho_find-${PYVERSSUFFIX} && \
	${MV} macho_standalone macho_standalone-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
