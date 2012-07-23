# $NetBSD: Makefile,v 1.10.10.1 2012/07/23 18:24:33 tron Exp $

MODNAME=		gettext
CATEGORIES+=		devel
COMMENT=		PHP extension for gettext support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-gettext-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gettext}

.include "../../lang/php/ext.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
