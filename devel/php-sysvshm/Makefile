# $NetBSD: Makefile,v 1.1.1.1 2004/10/31 19:30:30 jdolecek Exp $

MODNAME=		sysvshm
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP extension for SysV shared memory support

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
