# $NetBSD: Makefile,v 1.56 2025/02/04 08:47:28 adam Exp $

DISTNAME=	paramiko-3.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/paramiko/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.paramiko.org/
COMMENT=	SSH2 protocol library
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.2:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-invoke>=2.0:../../sysutils/py-invoke
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.5:../../security/py-nacl
# gssapi
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.7:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-gssapi>=1.4.1:../../security/py-gssapi
TEST_DEPENDS+=	${PYPKGPREFIX}-icecream-[0-9]*:../../misc/py-icecream
TEST_DEPENDS+=	${PYPKGPREFIX}-test-relaxed>=1.1.5:../../devel/py-test-relaxed

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
