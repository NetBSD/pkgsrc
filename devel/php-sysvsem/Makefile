# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:06 rillig Exp $

MODNAME=		sysvsem
CATEGORIES+=		devel
COMMENT=		PHP extension for SysV semaphore support


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
