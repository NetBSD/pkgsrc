# $NetBSD: Makefile,v 1.55 2023/11/08 13:20:33 wiz Exp $

MODNAME=		yaz
PECL_VERSION=		1.2.3
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		net

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ
PKGREVISION=		7
LICENSE=		modified-bsd

PHP_VERSIONS_ACCEPTED=	56 74

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
