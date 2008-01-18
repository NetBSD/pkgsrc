# $NetBSD: Makefile,v 1.2 2008/01/18 05:08:48 tnn Exp $

MODNAME=		yaz
PECL_VERSION=		1.0.7
PKGREVISION=		1
CATEGORIES+=		net
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
