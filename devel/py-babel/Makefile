# $NetBSD: Makefile,v 1.10 2013/10/11 14:25:24 obache Exp $
#

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

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	32

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
