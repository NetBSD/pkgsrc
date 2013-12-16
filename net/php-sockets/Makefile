# $NetBSD: Makefile,v 1.11.8.1 2013/12/16 17:05:48 tron Exp $

MODNAME=		sockets
CATEGORIES+=		net
COMMENT=		PHP extension for sockets support

CONFLICTS=	php-sockets-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

USE_PHP_EXT_PATCHES=	Yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	ac_cv_func_if_indextoname=yes
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
