# $NetBSD: Makefile,v 1.9 2004/04/24 23:25:23 xtraeme Exp $

MODNAME=		gettext
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for gettext support

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gettext}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
