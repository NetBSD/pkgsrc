# $NetBSD: Makefile,v 1.3 2002/02/28 06:18:18 jlam Exp $

MODNAME=		mbstring
CATEGORIES+=		misc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for multibyte characters support (currently, Japanese only)

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
