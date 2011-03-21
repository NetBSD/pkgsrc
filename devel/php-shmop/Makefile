# $NetBSD: Makefile,v 1.10 2011/03/21 16:08:28 taca Exp $

MODNAME=		shmop
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for simple SysV shared memory operations

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-shmop-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
