# $NetBSD: Makefile,v 1.11 2025/02/08 03:15:21 taca Exp $

MODNAME=		sysvsem
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for SysV semaphore support

CONFLICTS=	php-sysvsem-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
