# $NetBSD: Makefile,v 1.5 2002/11/30 15:13:24 taca Exp $

MODNAME=		mbstring
CATEGORIES+=		misc
PKGREVISION=		1
COMMENT=		PHP4 extension for multibyte characters support (currently, Japanese only)

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
