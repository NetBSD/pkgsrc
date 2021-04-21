# $NetBSD: Makefile,v 1.210 2021/04/21 11:40:27 adam Exp $

DISTNAME=	node-v14.16.1
EXTRACT_SUFX=	.tar.xz

USE_LANGUAGES=	c gnu++14

PKGREVISION= 1
.include "../../mk/bsd.prefs.mk"

# XXX: figure out a way to add rpaths to torque
MAKE_ENV+=	LD_LIBRARY_PATH=${PREFIX}/lib

CONFIGURE_ARGS+=	--shared-nghttp2
# ICU 69.1: error: 'createInstance' is a private member of 'icu_69::ListFormatter'
#CONFIGURE_ARGS+=	--with-intl=system-icu

PYTHON_VERSIONS_ACCEPTED=	27

CHECK_PORTABILITY_SKIP+=	tools/macos-installer/pkgbuild/npm/scripts/preinstall

.if ${MACHINE_ARCH} == "i386"
# required for SSE2 code under i386.
CXXFLAGS+=	-mstackrealign
.endif

.include "options.mk"

# Node turns on -latomic for arm, mips and ppc.
.if !empty(MACHINE_ARCH:M*arm*) || \
    !empty(MACHINE_ARCH:M*powerpc*) || \
    !empty(MACHINE_ARCH:M*mips*)
.include "../../devel/libatomic/buildlink3.mk"
.endif

.include "../../lang/nodejs/Makefile.common"
#.include "../../textproc/icu/buildlink3.mk"
# Requires nghttp2_option_set_max_settings
BUILDLINK_API_DEPENDS.nghttp2+=	nghttp2>=1.41.0
.include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
