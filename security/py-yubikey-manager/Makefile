#	$NetBSD: Makefile,v 1.7 2022/10/19 14:25:20 nia Exp $

.include "../../security/ykman/version.mk"

DISTNAME=	yubikey-manager-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Yubico/}
GITHUB_PROJECT=	yubikey-manager
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/yubikey-manager/
COMMENT=	Yubico YubiKey manager library
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-fido2>=0:../../security/py-fido2
DEPENDS+=	${PYPKGPREFIX}-scard>=0:../../devel/py-scard
DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-usb>=0:../../devel/py-usb

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-usb

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ykman ykman-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../security/ykpers/buildlink3.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
