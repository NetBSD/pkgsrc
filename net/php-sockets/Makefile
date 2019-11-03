# $NetBSD: Makefile,v 1.16 2019/11/03 11:45:49 rillig Exp $

MODNAME=		sockets
CATEGORIES+=		net
COMMENT=		PHP extension for sockets support

CONFLICTS=	php-sockets-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

USE_PHP_EXT_PATCHES=	Yes

CONFIGURE_ARGS.SunOS+=	ac_cv_func_if_indextoname=yes

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) || !empty(CC_VERSION:Mgcc-[6-9]*)
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=600
.else
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=500	# msghdr extensions
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
