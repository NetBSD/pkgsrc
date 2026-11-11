# $NetBSD: Makefile,v 1.65 2026/11/11 11:55:09 wiz Exp $

MODNAME=		yaz
PECL_VERSION=		1.2.4
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		net

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ
PKGREVISION=		3
LICENSE=		modified-bsd

PHP_VERSIONS_ACCEPTED=	74 82 83 84

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
