# $NetBSD: Makefile,v 1.17 2026/09/02 19:01:41 wiz Exp $

PKGNAME=	poco-${POCO_VERSION}
PKGREVISION=	1
CATEGORIES=	devel

COMMENT=	POCO C++ Foundation libraries

.include "../../devel/poco/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DPOCO_MINIMAL_BUILD=ON
# exceptions from the mininal build
CMAKE_CONFIGURE_ARGS+=	-DENABLE_CRYPTO=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_ENCODINGS=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_JSON=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_JWT=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NET=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NETSSL=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PAGECOMPILER=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PAGECOMPILER_FILE2PAGE=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_UTIL=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_XML=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_ZIP=ON

.include "../../converters/utf8proc/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
