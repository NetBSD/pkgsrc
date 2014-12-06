# $NetBSD: Makefile,v 1.1 2014/12/06 03:12:25 rodent Exp $

DISTNAME=	rednose-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/r/rednose/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://gfxmonk.net/dist/0install/rednose.xml
COMMENT=	Coloured output for nosetests
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-python-termstyle>=0.1.7:../../comms/py-python-termstyle

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
