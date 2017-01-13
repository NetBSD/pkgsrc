# $NetBSD: Makefile,v 1.8 2017/01/13 17:32:47 kleink Exp $

DISTNAME=	CairoSVG-1.0.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	converters graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CairoSVG/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.cairosvg.org/
COMMENT=	Simple SVG Converter for Cairo
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-cairocffi-[0-9]*:../../graphics/py-cairocffi

USE_LANGUAGES=	# none

PY_PATCHPLIST=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/cairosvg \
		${DESTDIR}${PREFIX}/bin/cairosvg${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
