# $NetBSD: Makefile,v 1.40 2022/01/11 08:03:02 adam Exp $

DISTNAME=	node-v12.22.9
EXTRACT_SUFX=	.tar.xz

USE_LANGUAGES=	c gnu++14

.include "../../mk/bsd.prefs.mk"

# XXX: figure out a way to add rpaths to torque
MAKE_ENV+=	LD_LIBRARY_PATH=${PREFIX}/lib

CONFIGURE_ARGS+=	--shared-brotli
CONFIGURE_ARGS+=	--shared-nghttp2
# ICU 69.1: error: 'createInstance' is a private member of 'icu_69::ListFormatter'
CONFIGURE_ARGS+=	--with-intl=system-icu

PYTHON_VERSIONS_ACCEPTED=	27

CHECK_PORTABILITY_SKIP+=	deps/openssl/openssl/.travis-create-release.sh
CHECK_PORTABILITY_SKIP+=	tools/macos-installer/*

.if ${MACHINE_ARCH} == "i386"
# required for SSE2 code under i386.
CXXFLAGS+=	-mstackrealign
.endif

.include "../../lang/nodejs/options.mk"

.include "../../lang/nodejs/Makefile.common"
.include "../../archivers/brotli/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
# Requires nghttp2_option_set_max_settings
BUILDLINK_API_DEPENDS.nghttp2+=	nghttp2>=1.41.0
.include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
