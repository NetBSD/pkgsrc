# $NetBSD: Makefile,v 1.3 2004/11/05 17:11:40 jdolecek Exp $

MODNAME=		sysvsem
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP extension for SysV semaphore support

USE_BUILDLINK3= 	YES

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
