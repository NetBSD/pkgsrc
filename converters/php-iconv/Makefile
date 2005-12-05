# $NetBSD: Makefile,v 1.6 2005/12/05 20:49:55 rillig Exp $

MODNAME=		iconv
CATEGORIES+=		converters
COMMENT=		PHP extension for character set conversion


.include "../../converters/libiconv/buildlink3.mk"

# This is necessary so that PHP would find either the libc iconv
# or use the packaged iconv, as appropriate; using
# --with-iconv=shared,${BUILDLINK_PREFIX.iconv} assumes libiconv exists
#
CHECK_BUILTIN.iconv:=	yes
.include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=	no

.if !empty(USE_BUILTIN.iconv:M[nN][oO]) || \
    !empty(BUILTIN_LIB_FOUND.iconv:M[yY][eE][sS])
CONFIGURE_ARGS+=	--with-iconv=shared,${BUILDLINK_PREFIX.iconv}
.else
CONFIGURE_ARGS+=	--with-iconv
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
