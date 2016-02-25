# $NetBSD: Makefile,v 1.14 2016/02/25 16:20:52 jperkin Exp $

MODNAME=		sockets
CATEGORIES+=		net
COMMENT=		PHP extension for sockets support

CONFLICTS=	php-sockets-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

USE_PHP_EXT_PATCHES=	Yes

CONFIGURE_ARGS.SunOS+=	ac_cv_func_if_indextoname=yes
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=500	# msghdr extensions

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
