# $NetBSD: Makefile,v 1.3 2017/05/05 06:50:01 adam Exp $

DISTNAME=	ldap3-2.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/ldap3/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/cannatag/ldap3
COMMENT=	Strictly RFC 4510 conforming LDAP V3 pure Python client library
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.8:../../security/py-asn1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
