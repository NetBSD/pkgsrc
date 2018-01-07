# $NetBSD: Makefile,v 1.12.2.1 2018/01/07 18:02:30 bsiegert Exp $

MODNAME=		iconv
CATEGORIES+=		converters
COMMENT=		PHP extension for character set conversion

CONFLICTS=	php-iconv-[0-9]*

INSTALLATION_DIRS+=	${PREFIX}/include/php/ext/iconv

PLIST_SRC+=		${.CURDIR}/PLIST

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

post-install:
	${INSTALL_DATA} ${WRKSRC}/php_iconv.h ${DESTDIR}${PREFIX}/include/php/ext/iconv

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
