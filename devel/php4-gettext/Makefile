# $NetBSD: Makefile,v 1.8 2003/08/31 19:55:38 jdolecek Exp $

MODNAME=		gettext
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for gettext support

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gettext}

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
