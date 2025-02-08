# $NetBSD: Makefile,v 1.14 2025/02/08 03:15:20 taca Exp $

MODNAME=		gettext
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for gettext support

CONFLICTS=	php-gettext-[0-9]*

CONFIGURE_ARGS+=	--with-gettext=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
