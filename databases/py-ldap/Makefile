# $NetBSD: Makefile,v 1.99 2025/10/16 09:36:01 adam Exp $

DISTNAME=	python_ldap-3.4.5
PKGNAME=	${DISTNAME:S/python_/${PYPKGPREFIX}-/}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-ldap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python-ldap.org/
COMMENT=	LDAP client API for Python
LICENSE=	python-software-foundation

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 099907
# Needs openldap>=2.4.48 for openldap.h.
# Unfortunately, version detection on the native version fails.
PREFER.openldap-client=	pkgsrc
.endif

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.3.7:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.1.5:../../security/py-asn1-modules
TEST_DEPENDS+=	openldap-server-[0-9]*:../../databases/openldap-server
TEST_ENV+=	BIN=${PREFIX}/bin
TEST_ENV+=	SBIN=${PREFIX}/sbin
TEST_ENV+=	SLAPD=${PREFIX}/libexec/slapd

BUILDLINK_API_DEPENDS.openldap-client+=	openldap-client>=2.4.48
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
