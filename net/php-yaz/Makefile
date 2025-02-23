# $NetBSD: Makefile,v 1.61 2025/02/23 09:23:03 taca Exp $

MODNAME=		yaz
PECL_VERSION=		1.2.4
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		net

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ
LICENSE=		modified-bsd

PHP_VERSIONS_ACCEPTED=	74 81 82 83 84

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
