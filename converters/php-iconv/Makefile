# $NetBSD: Makefile,v 1.14 2024/09/25 07:30:54 adam Exp $

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

.include "../../mk/bsd.prefs.mk"

.if ${USE_BUILTIN.iconv:U:tl} == no || ${BUILTIN_LIB_FOUND.iconv:U:tl} == yes
# Hack: allow building on Darwin without Command Line Tools.
.  if ${OPSYS} == "Darwin" && ${BUILDLINK_PREFIX.iconv} == "/usr" && !exists(/usr/include/iconv.h)
CONFIGURE_ARGS+=	--with-iconv=shared,${OSX_SDK_PATH:Q}/${BUILDLINK_PREFIX.iconv}
.  else
CONFIGURE_ARGS+=	--with-iconv=shared,${BUILDLINK_PREFIX.iconv}
.  endif
.else
CONFIGURE_ARGS+=	--with-iconv
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/php_iconv.h ${DESTDIR}${PREFIX}/include/php/ext/iconv

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
