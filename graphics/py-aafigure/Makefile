# $NetBSD: Makefile,v 1.5 2013/12/06 12:11:15 obache Exp $
#

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

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
