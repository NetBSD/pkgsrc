# $NetBSD: Makefile,v 1.3 2025/04/15 15:17:49 adam Exp $

DISTNAME=	pypng-0.20220715.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/drj11/pypng
COMMENT=	Pure Python library for saving and loading PNG images
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
.for bin in prichunkpng pricolpng priditherpng priforgepng prigreypng \
	pripalpng pripamtopng priplan9topng pripnglsch pripngtopam \
	prirowpng priweavepng
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
