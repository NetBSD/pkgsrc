# $NetBSD: Makefile,v 1.2 2001/10/16 06:41:09 jlam Exp $

.include "../php4/Makefile.module"

MODNAME=		sysvsem
CATEGORIES+=		devel
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for SysV semaphore support

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
