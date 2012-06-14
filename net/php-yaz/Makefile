# $NetBSD: Makefile,v 1.17 2012/06/14 07:44:47 sbd Exp $

MODNAME=		yaz
PECL_VERSION=		1.1.1
PECL_LEGACY_VERSION_SCHEME=	yes
PKGREVISION=		2
CATEGORIES+=		net
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
