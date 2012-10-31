# $NetBSD: Makefile,v 1.13 2012/10/31 11:19:23 asau Exp $

MODNAME=		gettext
CATEGORIES+=		devel
COMMENT=		PHP extension for gettext support

CONFLICTS=	php-gettext-[0-9]*

CONFIGURE_ARGS+=	--with-gettext=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
