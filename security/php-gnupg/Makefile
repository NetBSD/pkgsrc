# $NetBSD: Makefile,v 1.6 2025/05/19 15:43:51 taca Exp $

MODNAME=		gnupg
PECL_VERSION=		1.5.2
CATEGORIES=		security

MAINTAINER=		tpaul@NetBSD.org
LICENSE=		modified-bsd
COMMENT=		PHP module for interacting with gnupg

CONFIGURE_ARGS+=	--with-gnupg=${PREFIX}/include

INSTALLATION_DIRS+=	${PHP_INCDIR}/ext/gnupg

.include "../../security/gpgme/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
