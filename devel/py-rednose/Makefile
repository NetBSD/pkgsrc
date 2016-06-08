# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:29 wiz Exp $

DISTNAME=	rednose-0.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rednose/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://gfxmonk.net/dist/0install/rednose.xml
COMMENT=	Coloured output for nosetests
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-python-termstyle>=0.1.7:../../comms/py-python-termstyle

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
