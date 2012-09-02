# $NetBSD: Makefile,v 1.12 2012/09/02 14:09:56 marino Exp $

MODNAME=		gettext
CATEGORIES+=		devel
COMMENT=		PHP extension for gettext support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-gettext-[0-9]*

CONFIGURE_ARGS+=	--with-gettext=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
