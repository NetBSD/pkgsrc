# $NetBSD: Makefile,v 1.1 2020/04/30 12:17:33 nikita Exp $

DISTNAME=	impacket-0.9.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/impacket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.secureauth.com/labs/open-source-tools/impacket
COMMENT=	Collection of Python classes for working with network protocols
LICENSE=	apache-1.1

DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-cryptodomex-[0-9]*:../../security/py-cryptodomex
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-ldap3-[0-9]*:../../databases/py-ldap3
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-ldapdomaindump-[0-9]*:../../net/py-ldapdomaindump

# \todo: tests want ldap3==2.5.1, we have 2.7.x
TEST_DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
