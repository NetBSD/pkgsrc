# $NetBSD: Makefile,v 1.2 2014/02/10 00:16:58 rodent Exp $

DISTNAME=	macholib-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/m/macholib/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://bitbucket.org/ronaldoussoren/macholib
COMMENT=	Mach-O header analysis and editing
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.11:../../graphics/py-altgraph

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	macholib/macho_dump.py macholib/macho_find.py
REPLACE_PYTHON+=	macholib/macho_standalone.py
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/macho_dump \
		${DESTDIR}${PREFIX}/bin/macho_dump${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/macho_find \
		${DESTDIR}${PREFIX}/bin/macho_find${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/macho_standalone \
		${DESTDIR}${PREFIX}/bin/macho_standalone${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
