# $NetBSD: Makefile,v 1.1 2015/08/23 14:20:55 leot Exp $

DISTNAME=	certifi-2015.04.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certifi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://certifi.io/
COMMENT=	Python package for providing Mozilla's CA Bundle
LICENSE=	isc

USE_LANGUAGES=	# none

# XXX: First 0 in Jan-Sep months should be ignored
EGG_NAME=	${DISTNAME:C/\.0([1-9])\./.\1./}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
