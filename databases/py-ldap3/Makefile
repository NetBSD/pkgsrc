# $NetBSD: Makefile,v 1.22 2026/08/11 09:57:37 adam Exp $

DISTNAME=	ldap3-2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/ldap3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cannatag/ldap3
COMMENT=	Strictly RFC 4510 conforming LDAP V3 pure Python client library
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.4.6:../../security/py-asn1
TEST_DEPENDS+=	${PYPKGPREFIX}-gssapi-[0-9]*:../../security/py-gssapi

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest discover -v -s test

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
