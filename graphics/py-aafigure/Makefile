# $NetBSD: Makefile,v 1.10 2016/06/08 17:43:33 wiz Exp $

DISTNAME=	aafigure-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aafigure/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://launchpad.net/aafigure
COMMENT=	ASCII art to image converter
LICENSE=	modified-bsd

DEPENDS+=	{${PYPKGPREFIX}-imaging-[0-9]*,${PYPKGPREFIX}-Pillow-[0-9]*}:../../graphics/py-imaging
DEPENDS+=	${PYPKGPREFIX}-reportlab-[0-9]*:../../print/py-reportlab

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-reportlab, py-imaging

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
