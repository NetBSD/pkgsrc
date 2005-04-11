# $NetBSD: Makefile,v 1.4 2005/04/11 21:46:39 tv Exp $

MODNAME=		mbstring
CATEGORIES+=		misc
PKGREVISION=		# empty
COMMENT=		PHP extension for multibyte characters support (currently, Japanese only)


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
