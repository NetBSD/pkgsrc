# $NetBSD: Makefile,v 1.2 2026/06/28 15:41:25 wiz Exp $

DISTNAME=	svglib-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/svglib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/deeplook/svglib
COMMENT=	Pure-Python library for reading and converting SVG
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-cssselect2>=0.2.0:../../textproc/py-cssselect2
DEPENDS+=	${PYPKGPREFIX}-lxml>=6.0.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-reportlab>=4.4.3:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-rlpycairo>=0.4.0:../../print/py-rlpycairo
DEPENDS+=	${PYPKGPREFIX}-tinycss2>=0.6.0:../../textproc/py-tinycss2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} svg2pdf svg2pdf-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
