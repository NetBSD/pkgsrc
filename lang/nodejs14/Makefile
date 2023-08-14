# $NetBSD: Makefile,v 1.12 2023/08/14 05:24:45 wiz Exp $

DISTNAME=	node-v14.21.3
PKGREVISION= 	3
EXTRACT_SUFX=	.tar.xz

USE_LANGUAGES=	c gnu++14

.include "../../mk/bsd.prefs.mk"

# XXX: figure out a way to add rpaths to torque
MAKE_ENV+=	LD_LIBRARY_PATH=${PREFIX}/lib

CONFIGURE_ARGS+=	--without-dtrace

PYTHON_VERSIONS_ACCEPTED=	27

CHECK_INTERPRETER_SKIP+=	lib/node_modules/corepack/shims/*.ps1
CHECK_PORTABILITY_SKIP+=	tools/macos-installer/pkgbuild/npm/scripts/preinstall

.if ${MACHINE_ARCH} == "i386"
# required for SSE2 code under i386.
CXXFLAGS+=	-mstackrealign
.endif

.include "../../lang/nodejs/options.mk"

# Node turns on -latomic for arm, mips and ppc.
.if ${MACHINE_ARCH:M*arm*} || \
    ${MACHINE_ARCH:M*powerpc*} || \
    ${MACHINE_ARCH:M*mips*}
.include "../../devel/libatomic/buildlink3.mk"
.endif

.include "../../lang/nodejs/Makefile.common"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
