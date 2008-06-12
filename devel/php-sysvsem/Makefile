# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:28 joerg Exp $

MODNAME=		sysvsem
CATEGORIES+=		devel
COMMENT=		PHP extension for SysV semaphore support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-sysvsem-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
