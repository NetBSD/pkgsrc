# $NetBSD: Makefile,v 1.6 2017/09/30 14:25:29 adam Exp $

DISTNAME=	cached-property-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cached-property/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydanny/cached-property
COMMENT=	Cached-property for decorating methods in classes
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

USE_LANGUAGES=	# none

# UnicodeDecodeError: 'ascii' codec can't decode byte 0xe2 in position 561: ordinal not in range(128)

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
