# $NetBSD: Makefile,v 1.17 2021/04/28 08:24:01 adam Exp $

DISTNAME=	aafigure-0.6
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aafigure/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/aafigure
COMMENT=	ASCII art to image converter
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-reportlab-[0-9]*:../../print/py-reportlab

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-pyphen

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} aafigure aafigure-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
