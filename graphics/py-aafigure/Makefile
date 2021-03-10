# $NetBSD: Makefile,v 1.16 2021/03/10 18:49:07 adam Exp $

DISTNAME=	aafigure-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aafigure/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/aafigure
COMMENT=	ASCII art to image converter
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-reportlab-[0-9]*:../../print/py-reportlab

PYTHON_VERSIONED_DEPENDENCIES=	Pillow

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} aafigure aafigure${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
