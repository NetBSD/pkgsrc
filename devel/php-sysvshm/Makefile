# $NetBSD: Makefile,v 1.7 2006/06/02 18:27:56 joerg Exp $

MODNAME=		sysvshm
CATEGORIES+=		devel
COMMENT=		PHP extension for SysV shared memory support

CONFLICTS=	php-sysvshm-[0-9]

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
