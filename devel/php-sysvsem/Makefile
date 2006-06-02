# $NetBSD: Makefile,v 1.7 2006/06/02 18:27:55 joerg Exp $

MODNAME=		sysvsem
CATEGORIES+=		devel
COMMENT=		PHP extension for SysV semaphore support

CONFLICTS=	php-sysvsem-[0-9]

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
