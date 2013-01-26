# $NetBSD: Makefile,v 1.19 2013/01/26 21:38:37 adam Exp $

MODNAME=		yaz
PECL_VERSION=		1.1.1
PECL_LEGACY_VERSION_SCHEME=	yes
PKGREVISION=		3
CATEGORIES+=		net
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
