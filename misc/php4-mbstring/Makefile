# $NetBSD: Makefile,v 1.7 2004/04/25 00:20:38 xtraeme Exp $

MODNAME=		mbstring
CATEGORIES+=		misc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for multibyte characters support (currently, Japanese only)

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
