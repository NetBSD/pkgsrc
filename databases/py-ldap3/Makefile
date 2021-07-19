# $NetBSD: Makefile,v 1.19 2021/07/19 07:05:44 adam Exp $

DISTNAME=	ldap3-2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/ldap3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cannatag/ldap3
COMMENT=	Strictly RFC 4510 conforming LDAP V3 pure Python client library
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.4.6:../../security/py-asn1
TEST_DEPENDS+=	${PYPKGPREFIX}-gssapi-[0-9]*:../../security/py-gssapi

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest discover -v -s test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
