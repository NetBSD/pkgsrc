# $NetBSD: Makefile,v 1.1 2021/07/04 12:40:40 wiz Exp $

DISTNAME=	requests-gssapi-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-gssapi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pythongssapi/requests-gssapi
COMMENT=	Python requests GSSAPI authentication library
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-gssapi-[0-9]*:../../security/py-gssapi
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
