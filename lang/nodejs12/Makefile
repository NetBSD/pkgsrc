# $NetBSD: Makefile,v 1.24 2020/11/05 09:06:57 ryoon Exp $

DISTNAME=	node-v12.19.0

USE_LANGUAGES=	c gnu++14

PKGREVISION= 1
.include "../../mk/bsd.prefs.mk"

# XXX: figure out a way to add rpaths to torque
MAKE_ENV+=	LD_LIBRARY_PATH=${PREFIX}/lib

CONFIGURE_ARGS+=	--shared-nghttp2
CONFIGURE_ARGS+=	--with-intl=system-icu

CHECK_PORTABILITY_SKIP+=	deps/openssl/openssl/.travis-create-release.sh
CHECK_PORTABILITY_SKIP+=	tools/macos-installer/*

.if ${MACHINE_ARCH} == "i386"
# 64 bit atomic ops are required
CXXFLAGS+=	-march=i586
# required for SSE2 code under i386.
CXXFLAGS+=	-mstackrealign
.endif

.include "../../lang/nodejs/options.mk"

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
# Requires nghttp2_option_set_max_settings
BUILDLINK_API_DEPENDS.nghttp2+=	nghttp2>=1.41.0
.include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
