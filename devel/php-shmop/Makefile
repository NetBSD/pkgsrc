# $NetBSD: Makefile,v 1.9.26.1 2011/03/22 06:22:17 sbd Exp $

MODNAME=		shmop
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for simple SysV shared memory operations

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-shmop-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
