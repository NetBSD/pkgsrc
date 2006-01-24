# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:31 wiz Exp $

MODNAME=		xmlrpc
PKGREVISION=		1
CATEGORIES+=		net
COMMENT=		PHP extension for XML-RPC support

HOMEPAGE=		http://xmlrpc-epi.sourceforge.net/

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/phpversion.mk"

.if ${PKG_PHP_VERSION} == 5
# the extension has been changed in PHP 5.1 to require libxml2; while
# there is some "compatibility" expat configure setting, it doesn't build
# with that
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}
.else
CONFIGURE_ARGS+=	--with-expat-dir=${BUILDLINK_PREFIX.expat}
.endif

.include "../../converters/libiconv/buildlink3.mk"

# This is necessary so that PHP would find either the libc iconv
# or use the packaged iconv, as appropriate; using
# --with-iconv=shared,${BUILDLINK_PREFIX.iconv} assumes libiconv exists
#
CHECK_BUILTIN.iconv:=   yes
.include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=   no

.if !empty(USE_BUILTIN.iconv:M[nN][oO]) || \
    !empty(BUILTIN_LIB_FOUND.iconv:M[yY][eE][sS])
CONFIGURE_ARGS+=        --with-iconv-dir=shared,${BUILDLINK_PREFIX.iconv}
.else
CONFIGURE_ARGS+=        --with-iconv-dir
.endif

.if ${PKG_PHP_VERSION} == 5
.include "../../textproc/libxml2/buildlink3.mk"
.else
.include "../../textproc/expat/buildlink3.mk"
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
