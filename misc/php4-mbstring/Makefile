# $NetBSD: Makefile,v 1.1.1.1 2001/10/19 07:30:09 kei Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		mbstring
CATEGORIES+=		misc
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for multibyte characters support (currently, Japanese only)

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
