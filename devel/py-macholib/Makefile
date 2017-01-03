# $NetBSD: Makefile,v 1.6 2017/01/03 13:23:02 jperkin Exp $

DISTNAME=	macholib-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/macholib/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://bitbucket.org/ronaldoussoren/macholib
COMMENT=	Mach-O header analysis and editing
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.11:../../graphics/py-altgraph

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	macholib/macho_dump.py macholib/macho_find.py
REPLACE_PYTHON+=	macholib/macho_standalone.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/macho_dump \
		${DESTDIR}${PREFIX}/bin/macho_dump${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/macho_find \
		${DESTDIR}${PREFIX}/bin/macho_find${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/macho_standalone \
		${DESTDIR}${PREFIX}/bin/macho_standalone${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
