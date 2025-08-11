# $NetBSD: Makefile,v 1.8 2025/08/11 09:51:12 taca Exp $

MODNAME=		gnupg
PECL_VERSION=		1.5.4
CATEGORIES=		security

MAINTAINER=		tpaul@NetBSD.org
LICENSE=		modified-bsd
COMMENT=		PHP module for interacting with gnupg

CONFIGURE_ARGS+=	--with-gnupg=${PREFIX}/include

INSTALLATION_DIRS+=	${PHP_INCDIR}/ext/gnupg

.include "../../security/gpgme/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
