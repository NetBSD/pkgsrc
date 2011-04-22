# $NetBSD: Makefile,v 1.10 2011/04/22 13:43:22 obache Exp $

MODNAME=		gettext
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for gettext support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-gettext-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gettext}

.include "../../lang/php/ext.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
