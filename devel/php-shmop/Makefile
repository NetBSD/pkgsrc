# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:36 tv Exp $

MODNAME=		shmop
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP extension for simple SysV shared memory operations


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
