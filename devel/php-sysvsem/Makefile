# $NetBSD: Makefile,v 1.10 2012/10/31 11:19:24 asau Exp $

MODNAME=		sysvsem
CATEGORIES+=		devel
COMMENT=		PHP extension for SysV semaphore support

CONFLICTS=	php-sysvsem-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
