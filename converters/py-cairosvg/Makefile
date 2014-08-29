# $NetBSD: Makefile,v 1.3 2014/08/29 02:40:00 rodent Exp $

DISTNAME=	CairoSVG-1.0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	converters graphics python
MASTER_SITES=	https://pypi.python.org/packages/source/C/CairoSVG/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.cairosvg.org/
COMMENT=	Simple SVG Converter for Cairo
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-cairocffi-[0-9]*:../../graphics/py-cairocffi

USE_LANGUAGES=	# none

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/cairosvg \
		${DESTDIR}${PREFIX}/bin/cairosvg${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
