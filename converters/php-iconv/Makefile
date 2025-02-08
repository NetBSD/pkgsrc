# $NetBSD: Makefile,v 1.18 2025/02/08 03:06:01 taca Exp $

MODNAME=		iconv
PKGREVISION=		2
CATEGORIES+=		converters
COMMENT=		PHP extension for character set conversion

CONFLICTS=	php-iconv-[0-9]*

INSTALLATION_DIRS+=	${PREFIX}/${PHP_INCDIR}/ext/iconv

PLIST_SRC+=		${.CURDIR}/PLIST

TEST_TARGET=		test

CHECK_BUILTIN.iconv:=	yes
.include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=	no

.include "../../mk/bsd.prefs.mk"

.if ${USE_BUILTIN.iconv:U:tl} == no
CONFIGURE_ARGS+=	--with-iconv=shared,${BUILDLINK_PREFIX.iconv}
# Hack: allow building on Darwin without Command Line Tools.
.elif ${OPSYS} == "Darwin" && !exists(/usr/include/iconv.h)
CONFIGURE_ARGS+=	--with-iconv=shared,${OSX_SDK_PATH:Q}/${BUILDLINK_PREFIX.iconv}
.else
CONFIGURE_ARGS+=	--with-iconv
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/php_iconv.h ${DESTDIR}${PREFIX}/${PHP_INCDIR}/ext/iconv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
