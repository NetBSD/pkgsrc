# $NetBSD: Makefile,v 1.7 2003/07/13 13:51:25 wiz Exp $

MODNAME=		gettext
CATEGORIES+=		devel
PKGREVISION=		1
COMMENT=		PHP4 extension for gettext support

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gettext}

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
