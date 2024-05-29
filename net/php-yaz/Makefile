# $NetBSD: Makefile,v 1.56 2024/05/29 16:34:01 adam Exp $

MODNAME=		yaz
PECL_VERSION=		1.2.3
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		net

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ
PKGREVISION=		8
LICENSE=		modified-bsd

PHP_VERSIONS_ACCEPTED=	56 74

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
