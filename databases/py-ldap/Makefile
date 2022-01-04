# $NetBSD: Makefile,v 1.90 2022/01/04 20:52:42 wiz Exp $

DISTNAME=	python-ldap-3.3.1
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-ldap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python-ldap.org/
COMMENT=	LDAP client API for Python
LICENSE=	python-software-foundation

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-[56789].*) && \
    empty(MACHINE_PLATFORM:MNetBSD-9.99.*)
# Needs openldap>=2.4.48 for openldap.h.
# Unfortunately, version detection on the native version fails.
PREFER.openldap-client=	pkgsrc
.endif

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
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
