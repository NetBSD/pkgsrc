# $NetBSD: Makefile,v 1.10 2010/12/17 07:36:09 obache Exp $

MODNAME=		yaz
PECL_VERSION=		1.0.14
PKGREVISION=		1
CATEGORIES+=		net
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
