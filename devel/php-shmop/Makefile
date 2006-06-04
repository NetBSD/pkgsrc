# $NetBSD: Makefile,v 1.8 2006/06/04 16:26:53 joerg Exp $

MODNAME=		shmop
CATEGORIES+=		devel
COMMENT=		PHP extension for simple SysV shared memory operations

CONFLICTS=	php-shmop-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
