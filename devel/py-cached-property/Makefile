# $NetBSD: Makefile,v 1.5 2017/01/01 14:43:32 wiz Exp $

DISTNAME=	cached-property-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cached-property/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydanny/cached-property
COMMENT=	Cached-property for decorating methods in classes
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

# UnicodeDecodeError: 'ascii' codec can't decode byte 0xe2 in position 561: ordinal not in range(128)
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 1.2.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
