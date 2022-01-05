# $NetBSD: Makefile,v 1.19 2022/01/05 15:41:05 wiz Exp $

DISTNAME=	macholib-1.15.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/macholib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ronaldoussoren/macholib
COMMENT=	Mach-O header analysis and editing
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.15:../../graphics/py-altgraph

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	macholib/macho_dump.py
REPLACE_PYTHON+=	macholib/macho_find.py
REPLACE_PYTHON+=	macholib/macho_standalone.py

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} macho_dump macho_dump-${PYVERSSUFFIX} && \
	${MV} macho_find macho_find-${PYVERSSUFFIX} && \
	${MV} macho_standalone macho_standalone-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
