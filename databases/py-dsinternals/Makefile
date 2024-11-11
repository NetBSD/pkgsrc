# $NetBSD: Makefile,v 1.2 2024/11/11 07:27:56 wiz Exp $

DISTNAME=	dsinternals-1.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dsinternals/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/p0dalirius/pydsinternals
COMMENT=	Directory Services Internals Library
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

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
