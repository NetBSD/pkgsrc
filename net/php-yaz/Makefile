# $NetBSD: Makefile,v 1.63 2026/01/07 08:48:25 wiz Exp $

MODNAME=		yaz
PECL_VERSION=		1.2.4
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		net

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ
PKGREVISION=		2
LICENSE=		modified-bsd

PHP_VERSIONS_ACCEPTED=	74 81 82 83 84

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
