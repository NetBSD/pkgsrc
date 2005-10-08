# $NetBSD: Makefile,v 1.1.1.1 2005/10/08 15:59:48 jdolecek Exp $

MODNAME=		xmlrpc
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP extension for XML-RPC support

HOMEPAGE=		http://xmlrpc-epi.sourceforge.net/

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-expat-dir=${BUILDLINK_PREFIX.expat}

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

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
