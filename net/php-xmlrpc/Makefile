# $NetBSD: Makefile,v 1.23 2020/11/05 09:08:55 ryoon Exp $

MODNAME=		xmlrpc
CATEGORIES+=		net
COMMENT=		PHP extension for XML-RPC support
PKGREVISION=		2

CONFLICTS=	php-xmlrpc-[0-9]*

HOMEPAGE=		http://xmlrpc-epi.sourceforge.net/

USE_PHP_EXT_PATCHES=	YES

.include "../../lang/php/phpversion.mk"

.if ${PKG_PHP_VERSION} != 56
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}
.endif

CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

.include "../../converters/libiconv/buildlink3.mk"

# This is necessary so that PHP would find either the libc iconv
# or use the packaged iconv, as appropriate; using
# --with-iconv=shared,${BUILDLINK_PREFIX.iconv} assumes libiconv exists
#
CHECK_BUILTIN.iconv:=	yes
.include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=	no

.if !empty(USE_BUILTIN.iconv:M[nN][oO])
CONFIGURE_ARGS+=	--with-iconv-dir=${BUILDLINK_PREFIX.iconv}
.else
CONFIGURE_ARGS+=	--with-iconv-dir
.endif

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
