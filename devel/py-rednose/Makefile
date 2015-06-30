# $NetBSD: Makefile,v 1.2 2015/06/30 22:51:56 rodent Exp $

DISTNAME=	rednose-0.4.3
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
