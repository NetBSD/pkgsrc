# $NetBSD: Makefile,v 1.2 2021/06/06 07:20:05 taca Exp $

MODNAME=		gnupg
PECL_VERSION=		1.5.0
CATEGORIES=		security

MAINTAINER=		tpaul@NetBSD.org
LICENSE=		modified-bsd
COMMENT=		PHP module for interacting with gnupg

CONFIGURE_ARGS+=	--with-gnupg=${PREFIX}/include

INSTALLATION_DIRS+=	include/php/ext/gnupg

.include "../../security/gpgme/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
