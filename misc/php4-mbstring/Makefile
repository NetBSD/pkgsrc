# $NetBSD: Makefile,v 1.2 2001/12/03 08:31:03 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		mbstring
CATEGORIES+=		misc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for multibyte characters support (currently, Japanese only)

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
