# $NetBSD: Makefile,v 1.6 2002/10/31 15:14:31 wiz Exp $

MODNAME=		gettext
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for gettext support

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gettext}

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
