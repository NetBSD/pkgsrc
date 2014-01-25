# $NetBSD: Makefile,v 1.6 2014/01/25 10:30:09 wiz Exp $

DISTNAME=	aafigure-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics converters python
MASTER_SITES=	http://pypi.python.org/packages/source/a/aafigure/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://launchpad.net/aafigure
COMMENT=	ASCII art to image converter
LICENSE=	modified-bsd

DEPENDS+=	{${PYPKGPREFIX}-imaging-[0-9]*,${PYPKGPREFIX}-Pillow-[0-9]*}:../../graphics/py-imaging
DEPENDS+=	${PYPKGPREFIX}-reportlab-[0-9]*:../../print/py-reportlab

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-reportlab, py-imaging

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
