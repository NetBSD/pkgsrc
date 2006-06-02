# $NetBSD: Makefile,v 1.7 2006/06/02 18:27:55 joerg Exp $

MODNAME=		gettext
CATEGORIES+=		devel
COMMENT=		PHP extension for gettext support

CONFLICTS=	php-gettext-[0-9]

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gettext}

.include "../../lang/php/ext.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
