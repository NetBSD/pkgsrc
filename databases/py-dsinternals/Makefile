# $NetBSD: Makefile,v 1.3 2025/04/14 11:31:11 adam Exp $

DISTNAME=	dsinternals-1.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dsinternals/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/p0dalirius/pydsinternals
COMMENT=	Directory Services Internals Library
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome

USE_LANGUAGES=	# none

SUBST_CLASSES+=		crypto
SUBST_STAGE.crypto=	pre-configure
SUBST_MESSAGE.crypto=	Switching from py-cryptodomex to py-cryptodome.
SUBST_FILES.crypto+=	dsinternals/common/cryptography/RSAKeyMaterial.py
SUBST_FILES.crypto+=	dsinternals/common/cryptography/X509Certificate2.py
SUBST_SED.crypto=	-e 's,Cryptodome,Crypto,'

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
