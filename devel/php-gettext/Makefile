# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:06 rillig Exp $

MODNAME=		gettext
CATEGORIES+=		devel
COMMENT=		PHP extension for gettext support


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gettext}

.include "../../lang/php/ext.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
