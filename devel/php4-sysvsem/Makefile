# $NetBSD: Makefile,v 1.3 2001/10/16 06:58:32 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		sysvsem
CATEGORIES+=		devel
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for SysV semaphore support

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
