# $NetBSD: Makefile,v 1.2 2024/11/11 07:28:36 wiz Exp $

DISTNAME=	pypng-0.20220715.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/drj11/pypng
COMMENT=	Pure Python library for saving and loading PNG images
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in prichunkpng pricolpng priditherpng priforgepng prigreypng \
	pripalpng pripamtopng priplan9topng pripnglsch pripngtopam \
	prirowpng priweavepng
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
