# $NetBSD: Makefile,v 1.12 2010/03/16 13:50:34 taca Exp $

MODNAME=		mbstring
PKGREVISION=		1
CATEGORIES+=		misc
COMMENT=		PHP extension for multibyte characters support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-mbstring-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
