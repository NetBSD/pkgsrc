# $NetBSD: Makefile,v 1.1.1.1 2004/10/02 10:10:59 jdolecek Exp $

MODNAME=		shmop
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for simple SysV shared memory operations

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
