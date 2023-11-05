# $NetBSD: Makefile,v 1.14 2023/11/05 23:55:59 wiz Exp $

.include "../../security/ykman/version.mk"

DISTNAME=	yubikey_manager-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	security sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Yubico/}
GITHUB_PROJECT=	yubikey-manager
GITHUB_RELEASE=	${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/yubikey-manager/
COMMENT=	Yubico YubiKey manager library
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry>=0:../../devel/py-poetry
TEST_DEPENDS+=	${PYPKGPREFIX}-makefun>=0:../../devel/py-makefun
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.2:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-click>=8:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-fido2>=1:../../security/py-fido2
DEPENDS+=	${PYPKGPREFIX}-scard>=2:../../devel/py-scard
DEPENDS+=	${PYPKGPREFIX}-keyring>=23.4:../../security/py-keyring

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ykman ykman-${PYVERSSUFFIX}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
# for non-rust support
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
