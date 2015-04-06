# $NetBSD: Makefile,v 1.27 2015/04/06 08:17:35 adam Exp $

MODNAME=		yaz
PECL_VERSION=		1.1.1
PECL_LEGACY_VERSION_SCHEME=	yes
PKGREVISION=		11
CATEGORIES+=		net
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
