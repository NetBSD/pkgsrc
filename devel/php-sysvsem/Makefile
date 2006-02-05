# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:50 joerg Exp $

MODNAME=		sysvsem
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for SysV semaphore support


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
