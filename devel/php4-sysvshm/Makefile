# $NetBSD: Makefile,v 1.2 2001/10/16 06:58:33 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		sysvshm
CATEGORIES+=		devel
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for SysV shared memory support

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
