# $NetBSD: Makefile,v 1.86 2020/06/18 16:58:46 adam Exp $

DISTNAME=	python-ldap-3.3.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-ldap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python-ldap.org/
COMMENT=	LDAP client API for Python
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.3.7:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.1.5:../../security/py-asn1-modules
TEST_DEPENDS+=	openldap-server-[0-9]*:../../databases/openldap-server
TEST_ENV+=	BIN=${PREFIX}/bin
TEST_ENV+=	SBIN=${PREFIX}/sbin
TEST_ENV+=	SLAPD=${PREFIX}/libexec/slapd

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
