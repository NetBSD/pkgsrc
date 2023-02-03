# $NetBSD: Makefile,v 1.4 2023/02/03 11:49:19 adam Exp $

DISTNAME=	node-v18.14.0
EXTRACT_SUFX=	.tar.xz

USE_LANGUAGES=	c gnu++17

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

.include "../../mk/bsd.prefs.mk"

# XXX: figure out a way to add rpaths to torque
MAKE_ENV+=	LD_LIBRARY_PATH=${PREFIX}/lib

CONFIGURE_ARGS+=	--shared-brotli
CONFIGURE_ARGS+=	--shared-nghttp2
CONFIGURE_ARGS+=	--shared-nghttp3
CONFIGURE_ARGS+=	--shared-ngtcp2
CONFIGURE_ARGS+=	--with-intl=system-icu
CONFIGURE_ARGS+=	--without-dtrace

PYTHON_VERSIONS_INCOMPATIBLE=	27

CHECK_PORTABILITY_SKIP+=	deps/uv/autogen.sh
CHECK_PORTABILITY_SKIP+=	deps/v8/tools/cppgc/export_to_github.sh
CHECK_PORTABILITY_SKIP+=	deps/v8/tools/cppgc/test_cmake.sh
CHECK_PORTABILITY_SKIP+=	tools/macos-installer/pkgbuild/npm/scripts/preinstall

REPLACE_NODEJS+=		deps/corepack/dist/*.js
.include "../../lang/nodejs/application.mk"
CHECK_INTERPRETER_SKIP+=	lib/node_modules/corepack/shims/*.ps1

.if ${MACHINE_ARCH} == "i386"
# required for SSE2 code under i386.
CXXFLAGS+=	-mstackrealign
.endif

.PHONY: minusx
post-install: minusx
minusx:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/node_modules/corepack/shims/*.cmd

.include "../../lang/nodejs/options.mk"

# Node turns on -latomic for arm, mips and ppc.
.if ${MACHINE_ARCH:M*arm*} || \
    ${MACHINE_ARCH:M*powerpc*} || \
    ${MACHINE_ARCH:M*mips*}
.include "../../devel/libatomic/buildlink3.mk"
.endif

.include "../../lang/nodejs/Makefile.common"
.include "../../archivers/brotli/buildlink3.mk"
.include "../../net/ngtcp2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
# Requires nghttp2_option_set_max_settings
BUILDLINK_API_DEPENDS.nghttp2+=	nghttp2>=1.41.0
.include "../../www/nghttp2/buildlink3.mk"
.include "../../www/nghttp3/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
