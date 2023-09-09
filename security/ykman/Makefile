# $NetBSD: Makefile,v 1.6 2023/09/09 21:37:49 wiz Exp $

.include "../../security/ykman/version.mk"

PKGNAME=	ykman-${VERSION}
CATEGORIES=	security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/yubikey-manager/
COMMENT=	Yubico YubiKey manager command-line tool
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-yubikey-manager>=${VERSION}:../../security/py-yubikey-manager

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
