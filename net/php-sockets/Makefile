# $NetBSD: Makefile,v 1.11 2012/10/23 17:18:58 asau Exp $

MODNAME=		sockets
CATEGORIES+=		net
COMMENT=		PHP extension for sockets support

CONFLICTS=	php-sockets-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	ac_cv_func_if_indextoname=yes
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
