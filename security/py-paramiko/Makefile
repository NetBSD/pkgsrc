# $NetBSD: Makefile,v 1.29 2017/10/12 12:42:26 adam Exp $

DISTNAME=	paramiko-2.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/paramiko/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/paramiko/paramiko
COMMENT=	SSH2 protocol library
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.7:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.3:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.5:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.0.1:../../security/py-nacl

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
