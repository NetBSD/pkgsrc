# $NetBSD: Makefile,v 1.32 2016/04/11 19:02:01 ryoon Exp $

MODNAME=		yaz
PECL_VERSION=		1.1.9
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		net

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ
PKGREVISION=		3
LICENSE=		modified-bsd

PHP_VERSIONS_ACCEPTED=	55 56

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
