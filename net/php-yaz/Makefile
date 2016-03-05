# $NetBSD: Makefile,v 1.31 2016/03/05 11:29:10 jperkin Exp $

MODNAME=		yaz
PECL_VERSION=		1.1.9
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		net

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ
PKGREVISION=		2
LICENSE=		modified-bsd

PHP_VERSIONS_ACCEPTED=	55 56

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
