# $NetBSD: Makefile,v 1.62 2026/07/21 12:55:54 adam Exp $

.include "../../devel/gettext/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-lib-/}
COMMENT=	Internationalized Message Handling Library (libintl)

USE_LANGUAGES=		c
CONFIGURE_ARGS+=	--with-included-gettext
CONFIGURE_ARGS+=	--disable-csharp
CONFIGURE_ARGS+=	--disable-c++
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
GNU_CONFIGURE_STRICT=	no # because of gettext-tools/examples

CFLAGS+=		${CFLAGS.${ICONV_TYPE}-iconv}
CFLAGS.gnu-iconv+=	-DHAVE_GNU_ICONV

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} localedir=${EGDIR}
INSTALL_MAKE_FLAGS+=	includedir=${PREFIX}/include/gettext

BUILD_DIRS=		gettext-runtime/intl

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
