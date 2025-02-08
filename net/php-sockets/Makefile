# $NetBSD: Makefile,v 1.18 2025/02/08 03:18:21 taca Exp $

MODNAME=		sockets
PKGREVISION=		1
CATEGORIES+=		net
COMMENT=		PHP extension for sockets support

CONFLICTS=	php-sockets-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

USE_PHP_EXT_PATCHES=	Yes

CONFIGURE_ARGS.SunOS+=	ac_cv_func_if_indextoname=yes

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) || !empty(CC_VERSION:Mgcc-[6-9]*) || !empty(CC_VERSION:Mgcc-1[0-9].*)
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=600
.else
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=500	# msghdr extensions
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
