# $NetBSD: Makefile,v 1.5 2002/11/05 07:33:15 martti Exp $

MODNAME=		sysvshm
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for SysV shared memory support

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
