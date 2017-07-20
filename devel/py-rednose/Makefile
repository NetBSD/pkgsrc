# $NetBSD: Makefile,v 1.4 2017/07/20 17:23:16 adam Exp $

DISTNAME=	rednose-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rednose/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/JBKahn/rednose
COMMENT=	Coloured output for nosetests
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-termstyle>=0.1.7:../../comms/py-termstyle

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
