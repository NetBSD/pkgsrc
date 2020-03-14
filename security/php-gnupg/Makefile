# $NetBSD: Makefile,v 1.1 2020/03/14 04:40:47 tpaul Exp $

MODNAME=		gnupg
PECL_VERSION=		1.4.0
CATEGORIES=		security

MAINTAINER=		tpaul@NetBSD.org
LICENSE=		modified-bsd
COMMENT=		PHP module for interacting with gnupg

CONFIGURE_ARGS+=	--with-gnupg=${PREFIX}/include

INSTALLATION_DIRS+=	include/php/ext/gnupg

.include "../../security/gpgme/buildlink3.mk"

.if !empty(PKG_BUILD_OPTIONS.gpgme:Mgnupg2)
PKG_FAIL_REASON+=	"gpgme should be built with gnupg1 option"
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
