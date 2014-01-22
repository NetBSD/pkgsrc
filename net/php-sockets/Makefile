# $NetBSD: Makefile,v 1.13 2014/01/22 12:26:11 jperkin Exp $

MODNAME=		sockets
CATEGORIES+=		net
COMMENT=		PHP extension for sockets support

CONFLICTS=	php-sockets-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

USE_PHP_EXT_PATCHES=	Yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	ac_cv_func_if_indextoname=yes
CFLAGS+=		-D_XOPEN_SOURCE=500	# msghdr extensions
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
