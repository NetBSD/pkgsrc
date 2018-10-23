# $NetBSD: Makefile,v 1.82 2018/10/23 08:58:27 adam Exp $

DISTNAME=	python-ldap-3.1.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-ldap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python-ldap.org/
COMMENT=	LDAP client API for Python
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.3.7:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.1.5:../../security/py-asn1-modules

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
