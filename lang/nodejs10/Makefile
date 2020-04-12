# $NetBSD: Makefile,v 1.8 2020/04/12 08:27:58 adam Exp $

DISTNAME=	node-v10.19.0

USE_LANGUAGES=	c gnu++14

# Requires http_parser_set_max_header_size
BUILDLINK_API_DEPENDS.http-parser+=	http-parser>=2.9.0

PKGREVISION= 1
.include "../../mk/bsd.prefs.mk"

# XXX: figure out a way to add rpaths to torque
MAKE_ENV+=	LD_LIBRARY_PATH=${PREFIX}/lib

CONFIGURE_ARGS+=	--shared-http-parser
CONFIGURE_ARGS+=	--shared-nghttp2
CONFIGURE_ARGS+=	--with-intl=system-icu

CHECK_PORTABILITY_SKIP+=	deps/openssl/openssl/.travis-create-release.sh

.if ${MACHINE_ARCH} == "i386"
# 64 bit atomic ops are required
CXXFLAGS+=	-march=i586
# required for SSE2 code under i386.
CXXFLAGS+=	-mstackrealign
.endif

.include "../../lang/nodejs/options.mk"

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
