# $NetBSD: Makefile,v 1.12 2014/01/25 10:30:02 wiz Exp $

DISTNAME=	Babel-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/B/Babel/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://babel.pocoo.org/
COMMENT=	Collection of tools for internationalizing Python applications
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
