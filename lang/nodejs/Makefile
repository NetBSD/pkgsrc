# $NetBSD: Makefile,v 1.161 2019/08/03 07:31:15 adam Exp $

DISTNAME=	node-v10.16.1

USE_LANGUAGES=	c gnu++14

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

# Stated by the changelog
BUILDLINK_API_DEPENDS.libuv+=	libuv>=1.23

# Requires http_parser_set_max_header_size
BUILDLINK_API_DEPENDS.http-parser+=	http-parser>=2.9.0

.include "../../mk/bsd.prefs.mk"

# XXX: figure out a way to add rpaths to torque
MAKE_ENV+=	LD_LIBRARY_PATH=${PREFIX}/lib

# Optional OpenSSL support in nghttp2 conflicts with OpenSSL 1.1.x
# bundled and built by lang/nodejs.
# Uncomment when we switch to openssl>=1.1
# CONFIGURE_ARGS+=	--shared-nghttp2
CONFIGURE_ARGS+=	--with-intl=system-icu

CHECK_PORTABILITY_SKIP+=	deps/openssl/openssl/.travis-create-release.sh

.if ${MACHINE_ARCH} == "i386"
# 64 bit atomic ops are required
CXXFLAGS+=	-march=i586
# required for SSE2 code under i386.
CXXFLAGS+=	-mstackrealign
.endif

.include "options.mk"

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
# Uncomment when we switch to openssl>=1.1
# .include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
