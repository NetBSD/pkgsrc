# $NetBSD: Makefile,v 1.10 2012/07/25 12:12:37 fhajny Exp $

MODNAME=		sockets
CATEGORIES+=		net
COMMENT=		PHP extension for sockets support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-sockets-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	ac_cv_func_if_indextoname=yes
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
