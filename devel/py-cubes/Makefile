# $NetBSD: Makefile,v 1.1 2017/06/01 12:05:28 adam Exp $

DISTNAME=	cubes-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cubes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cubes.databrewery.org/
COMMENT=	Lightweight framework for Online Analytical Processing
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-expressions-[0-9]*:../../devel/py-expressions
DEPENDS+=	${PYPKGPREFIX}-jsonschema-[0-9]*:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.9.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug

USE_LANGUAGES=		# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv slicer slicer${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
