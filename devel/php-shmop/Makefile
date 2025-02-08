# $NetBSD: Makefile,v 1.13 2025/02/08 03:15:21 taca Exp $

MODNAME=		shmop
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for simple SysV shared memory operations

CONFLICTS=	php-shmop-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
