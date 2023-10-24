# $NetBSD: Makefile,v 1.293 2023/10/24 22:09:40 wiz Exp $

DISTNAME=	rustc-1.71.1-src
PKGNAME=	${DISTNAME:S/rustc/rust/:S/-src//}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://static.rust-lang.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

CONFLICTS+=	rust-bin-[0-9]*

# LLVM requires gcc7, follow suit.  Also, uses -std=c++17
USE_CXX_FEATURES+=	c++17

USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++17
USE_LIBTOOL=		yes
USE_TOOLS+=		bash grep gmake perl:build pkg-config

# The NetBSD bootstraps are built for NetBSD 8 (because rust doesn't
# build on 7).  Mark earlier versions as broken.
BROKEN_ON_PLATFORM+=	NetBSD-[1-7].*-*
# Bootstrap is built for NetBSD 9.x on these platforms:
BROKEN_ON_PLATFORM+=	NetBSD-8.*-*arm*
BROKEN_ON_PLATFORM+=	NetBSD-8.*-aarch64
BROKEN_ON_PLATFORM+=	NetBSD-8.*-sparc64

HAS_CONFIGURE=		yes
PYTHON_FOR_BUILD_ONLY=	yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	src/bootstrap/configure.py
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--python=${PYTHONBIN}
CONFIGURE_ARGS+=	--release-channel=stable
CONFIGURE_ARGS+=	--local-rust-root=${RUST_BOOTSTRAP_PATH}
CONFIGURE_ARGS+=	--enable-extended	# Build and install cargo too.
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--disable-codegen-tests
CONFIGURE_ARGS+=	--disable-compiler-docs
CONFIGURE_ARGS+=	--disable-llvm-static-stdcpp
CONFIGURE_ARGS+=	--disable-ninja
CONFIGURE_ARGS+=	--dist-compression-formats=xz

# Include (optional) settings to cross-build rust
.include "cross.mk"

# optional from do-cross.mk
CONFIGURE_ARGS+=	${ADD_CONFIGURE_ARGS}

# Getting RPATH with $ORIGIN into bootstrap may be troublesome, so
# uncommenting the LD_LIBRARY_PATH setting may be required to run
# the bootstrap
PKGSRC_MAKE_ENV+=	LD_LIBRARY_PATH=${RUST_BOOTSTRAP_PATH:Q}/lib

# This should allow us to perform "offline" builds (so cargo doesn't fetch
# dependencies during the build stage) but this isn't hooked up yet.
CONFIGURE_ARGS+=	--enable-vendor

# cargo defaults to using the number of available CPUs
MAKE_ENV+=		CARGO_BUILD_JOBS=${_MAKE_JOBS_N}

# Rust builds some bundled components with strict version requirements, ensure
# that any conflicting packages pulled in via dependencies are not buildlinked.
BUILDLINK_FILES_CMD.libssh2=	${TRUE}
BUILDLINK_FILES_CMD.xz=		${TRUE}
MAKE_ENV+=			LZMA_API_STATIC=1

# MacOS X 10.7 is the oldest supported version. See
# ${WRKSRC}/src/bootstrap/lib.rs
MAKE_ENV.Darwin+=	MACOSX_DEPLOYMENT_TARGET="10.7"

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS
MAKE_ENV.SunOS+=	AR=gar

UNLIMIT_RESOURCES+=	cputime stacksize datasize virtualsize

TEST_TARGET=	check

# bin/* lib/*, but names vary
CHECK_RELRO_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no

.include "../../mk/bsd.prefs.mk"

# Allow overriding MAKE_JOBS_SAFE
# some may chose to mostly build faster,
# and deal with any failures due to deadlocks
.if !empty(rust.MAKE_JOBS_SAFE)
.  if ${rust.MAKE_JOBS_SAFE:tl} == "yes"
MAKE_JOBS_SAFE=		yes
.  endif
.endif

.if !empty(rust.BUILD_TARGET)
BUILD_TARGET=	${rust.BUILD_TARGET}
.endif

.if !empty(TARGET)
# Use "dist" build target for cross compile of bootstrap
BUILD_TARGET?=		dist
.else
BUILD_TARGET?=		build
.endif

.if ${MACHINE_PLATFORM:MNetBSD-*-powerpc} || \
    ${MACHINE_PLATFORM:MNetBSD-*-earmv[67]hf} || \
    ${MACHINE_PLATFORM:MNetBSD-*-mipsel} || \
    !empty(TARGET:Marmv[67]-unknown-netbsd-eabihf) || \
    !empty(TARGET:Mmipsel-unknown-netbsd)
# Bootstrapping on NetBSD/powerpc requires no debug-info from rustc
# (both for amd64->powerpc built and powerpc->powerpc built bootstrap bits)
# Also try to downsize the armv[67] build.
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-debug-assertions
CONFIGURE_ARGS+=	--disable-llvm-release-debuginfo
CONFIGURE_ARGS+=	--debuginfo-level=0
CONFIGURE_ARGS+=	--debuginfo-level-rustc=0
CONFIGURE_ARGS+=	--debuginfo-level-std=0
CONFIGURE_ARGS+=	--debuginfo-level-tools=0
CONFIGURE_ARGS+=	--debuginfo-level-tests=0
.endif

# Only build the ARM target on/for this host, due to resource constraints
.if ${MACHINE_PLATFORM:MNetBSD-*-earmv[67]hf}
CONFIGURE_ARGS+=	--set llvm.targets="ARM"
.endif
# When cross-building for ARM on X86, X86 needs to go along due
# to 2-stage build process
.if !empty(TARGET:Marmv[67]-unknown-netbsd-eabihf)
CONFIGURE_ARGS+=	--set llvm.targets="ARM;X86"
.endif
# Same for mips:
.if ${MACHINE_PLATFORM:MNetBSD-*-mipsel}
CONFIGURE_ARGS+=	--set llvm.targets="Mips"
.endif
.if !empty(TARGET:Mmipsel-unknown-netbsd)
CONFIGURE_ARGS+=	--set llvm.targets="Mips;X86"
.endif

CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/backtrace/ci/android-sdk.sh
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/backtrace/ci/debuglink.sh
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/backtrace/ci/run.sh
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/backtrace/ci/run-docker.sh
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/core/src/unicode/printable.py
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/stdarch/ci/build-std-detect.sh
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/stdarch/ci/dox.sh
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/stdarch/ci/run-docker.sh
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/stdarch/ci/run.sh
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/stdarch/ci/style.sh

.if ${OPSYS} == "NetBSD"
# This block contains information about known trouble on NetBSD and workarounds.

# Parallel builds failed on NetBSD due to dynamic linker locking bugs.
# \todo Explain if the build is believed to be sound if not parallel,
# or if a non-parallel build is merely more likely to work.
#
# See toolchain/54192 at
#   http://gnats.netbsd.org/cgi-bin/query-pr-single.pl?number=54192
# which was fixed in -current on 2020-04-19:
#   http://mail-index.netbsd.org/source-changes/2020/04/16/msg116256.html
#   http://mail-index.netbsd.org/source-changes/2020/04/19/msg116337.html
# These  were pulled up to netbsd-9 on 2020-05-13:
#   http://releng.netbsd.org/cgi-bin/req-9.cgi?show=907
# This has not been pulled up to netbsd-8
#   \todo Explain if it's not applicable, shouldn't be pulled up, should be
#   but hasn't, is too hard, etc.
#
# On pkgbuild for 2020Q1 9.0_RELEASE amd64, rust did not build despite
# MAKE_JOBS_SAFE=no, but setting MAKE_JOBS=1 resulted in success. (No
# PR is open for this.)  \todo Understand and fix.
#
# If we aren't on 9-current, and are on 8.x or 9.x, avoid parallel.
# Release 9.x and 9.1 or later is OK.
.  if ${OPSYS} == "NetBSD" && 090999 < ${OPSYS_VERSION} && ${OPSYS_VERSION} < 090900
MAKE_JOBS_SAFE?=	no
.  endif

# Open PRs
#
# Broken package with PREFIX not /usr/pkg:
#   http://gnats.netbsd.org/cgi-bin/query-pr-single.pl?number=54453
#

.endif

#
# Under NetBSD, do not use DT_RUNPATH
#
BUILDLINK_TRANSFORM.NetBSD+=	rm:-Wl,--enable-new-dtags

#
# Somewhere in the LLVM build "-arch x86_64" is passed on macOS/arm64 which
# breaks linking, see https://github.com/rust-lang/rust/issues/81790.  Until
# this can be located (proving difficult!) we just force it.
#
.if ${MACHINE_PLATFORM:MDarwin-*-aarch64}
BUILDLINK_TRANSFORM+=	opt:x86_64:arm64
.endif

#
# Rust unfortunately requires itself to build.  On platforms which aren't
# supported by upstream (where they offer binary bootstraps), or where we do
# not trust random binaries from the Internet, we need to build and provide our
# own bootstrap.  See the stage0-bootstrap below for more details.
#
DISTFILES:=		${DEFAULT_DISTFILES}

.if ${MACHINE_PLATFORM:MDarwin-*-aarch64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.70.0
RUST_ARCH:=		aarch64-apple-darwin
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MDarwin-*-x86_64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.70.0
RUST_ARCH:=		x86_64-apple-darwin
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MLinux-*-aarch64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.70.0
RUST_ARCH:=		aarch64-unknown-linux-gnu
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MLinux-*-earmv6hf} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.70.0
RUST_ARCH:=		arm-unknown-linux-gnueabihf
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MLinux-*-earmv7hf} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.70.0
RUST_ARCH:=		armv7-unknown-linux-gnueabihf
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MLinux-*-i386} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.70.0
RUST_ARCH:=		i686-unknown-linux-gnu
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MLinux-*-x86_64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.70.0
RUST_ARCH:=		x86_64-unknown-linux-gnu
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
#
# The SunOS target defaults to illumos as that's what the current bootstraps
# are built on.  If you wish to target Oracle Solaris you'll need to create an
# x86_64-sun-solaris bootstrap and comment out the overrides.
#
.if ${MACHINE_PLATFORM:MSunOS-*-x86_64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.70.0
RUST_ARCH:=		x86_64-unknown-illumos
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
SITES.${RUST_STAGE0}=	https://us-central.manta.mnx.io/pkgsrc/public/pkg-bootstraps/
DISTFILES:=		${DISTFILES} ${RUST_STAGE0}
RUST_BOOTSTRAP_PATH?=	${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH}
# Override default "x86_64-sun-solaris" selection
CONFIGURE_ARGS+=	--set=target.${RUST_ARCH}.llvm-config=${LLVM_CONFIG_PATH}
CONFIGURE_ARGS+=	--build=${RUST_ARCH}
CONFIGURE_ARGS+=	--host=${RUST_ARCH}
CONFIGURE_ARGS+=	--target=${RUST_ARCH}
.endif
.if ${MACHINE_PLATFORM:MFreeBSD-*-x86_64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.70.0
RUST_ARCH:=		x86_64-unknown-freebsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-i386} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.70.0
RUST_ARCH=		i586-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
SITES.${RUST_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
# Setting this changes it for every distfile, which doesn't match what is
# currently in distinfo.
#DIST_SUBDIR=		${PKGNAME}
# For atomic ops
CFLAGS+=		-march=i586
CONFIGURE_ARGS+=	--build=${RUST_ARCH}
pre-build: pre-build-fix-paxctl
.PHONY: pre-build-fix-paxctl
pre-build-fix-paxctl:
	${TOOLS_PLATFORM.paxctl} +am ${WRKDIR}/rust-bootstrap/bin/cargo
	${TOOLS_PLATFORM.paxctl} +am ${WRKDIR}/rust-bootstrap/bin/rustc
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-x86_64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.70.0
RUST_ARCH=		x86_64-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-powerpc} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.70.0
RUST_ARCH=		powerpc-unknown-netbsd

# Cross-built against NetBSD 9.0
.  if empty(OS_VERSION:M8.*) || make(distinfo) || make(makesum) || make(mdi)
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}90.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}90.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.  endif

# Cross-built against NetBSD 8.0
.  if !empty(OS_VERSION:M8.*) || make(distinfo) || make(makesum) || make(mdi)
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.  endif

.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=		1.70.0
RUST_ARCH=			aarch64-unknown-netbsd
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64eb} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=		1.70.0
RUST_ARCH=			aarch64_be-unknown-netbsd
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-sparc64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=		1.70.0
RUST_ARCH=			sparc64-unknown-netbsd
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-earmv7hf} || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH=			armv7-unknown-netbsd-eabihf
RUST_STAGE0_VER=		1.70.0
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-earmv6hf} || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH=			armv6-unknown-netbsd-eabihf
RUST_STAGE0_VER=		1.70.0
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-mipsel} || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH=			mipsel-unknown-netbsd
RUST_STAGE0_VER=		1.70.0
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-riscv64} || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH=			riscv64gc-unknown-netbsd
RUST_STAGE0_VER=		1.70.0
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.endif

# You may override RUST_BOOTSTRAP_PATH and RUST_ARCH in mk.conf
# if you have a local bootstrap compiler.
.if !defined(RUST_ARCH) && !defined(RUST_BOOTSTRAP_PATH)
NOT_FOR_PLATFORM+=	${MACHINE_PLATFORM}
.else
RUST_BOOTSTRAP_PATH?=	${WRKDIR}/rust-bootstrap
.endif

.if ${OPSYS} == "SunOS"
TOOL_DEPENDS+=		coreutils>=0:../../sysutils/coreutils
TOOL_DEPENDS+=		gzip>=0:../../archivers/gzip
TOOLS_CREATE+=		md5sum
TOOLS_PATH.md5sum=	${PREFIX}/bin/gmd5sum
TOOLS_PLATFORM.gzcat=	${PREFIX}/bin/gzip -cd
.endif

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_FILES.rpath+=	compiler/rustc_codegen_ssa/src/back/linker.rs
SUBST_FILES.rpath+=	compiler/rustc_target/src/spec/netbsd_base.rs
SUBST_FILES.rpath+=	src/bootstrap/builder.rs
SUBST_FILES.rpath+=	src/bootstrap/compile.rs
SUBST_VARS.rpath=	PREFIX

#
# Generate list of subst entries for various .cargo-checksum.json files.  These
# are all handled together in one big substitution to simplify things rather
# than one substitution entry per file, but are kept separate below to ease
# updating and verification.
#

CKSUM_CRATES+=	vendor/cc-1.0.73
CKSUMS+=	38970d678de0efb4b5e2978265daa8a613a1db35fc42e669621b03fc56d5b138
CKSUMS+=	65de0d6593a4256e5fcaf898f9468d71bab672c70a2dfab3dcb8514e9b72819c

CKSUM_CRATES+=	vendor/cc-1.0.77
CKSUMS+=	2403bbe39ff511ea5a517c0841d825173a4fdc8a0899c64282bba49127f0dc33
CKSUMS+=	2b7150f466b9e0617b2c3755450db2090232f27561687d462b0a8ac0518fce87

CKSUM_CRATES+=	vendor/cc
CKSUMS+=	17a4659710aa290c4ed9c23063c7b202c5bcf2a84de33aa1f01fc6fded69a1f8
CKSUMS+=	a19bcb1a561d4ba5846f8f89fcfe6f05a3cb2e79baf8f21f53f0fba012db1b7f

CKSUM_CRATES+=	vendor/libc
CKSUMS+=	247154ad4f5e5114a2bb572bff0d157ed3b937a373759146b7d0f2900203293b
CKSUMS+=	a23a255e9793ecf674ddb8cdb5ea9b71999d1bddbaf26bf930e425aa6d2a8bc7
CKSUMS+=	55ce4624745e31ad226b47fde177a46176a89da3fa5030663673a115102471f9
CKSUMS+=	09ab15cd50245f4ced230b7919657ab170e06443bb0ed4baf4449d3472f5f656

CKSUM_CRATES+=	vendor/libc-0.2.139
CKSUMS+=	107a4aa396b8383c66e0ace2f941450b4b69146558cdc4d9fbe33eeab51760f1
CKSUMS+=	4be83bef456569d59405edf134e7fe8eff78f3fe35f1efd60e15405d5c822725

CKSUM_CRATES+=	vendor/libc-0.2.140
CKSUMS+=	4493317993af390d8aafc2cb7ace4c349dfc9d2451fd666844f04a4fa1f47442
CKSUMS+=	e5414483c02597e67a0aa27db7501f1a98c43ffee0151aa320586dded51f41cb

CKSUM_CRATES+=	vendor/libc-0.2.143
CKSUMS+=	88e7667202668ca4f7e63b22b56b3d15e78ecc1481d3528ede6ef4728cafa1b4
CKSUMS+=	8f32aab5222247a2afbd7b96c4c48d744a941567d07484fda9fe6a5aae54b75d

CKSUM_CRATES+=	vendor/lzma-sys
CKSUMS+=	6fd5e9245db34c6f557b8bfcaf03db82fc88c3b06dbfbb5f03b2bcd138983ef9
CKSUMS+=	5e252578b5d266f6a4c8dc9f71ca7a91536ccb8c5c7d7753b82f12ec886459ef

CKSUM_CRATES+=	vendor/stacker
CKSUMS+=	59ca847887cf19387119d18c57f08d5a8520d714876ca0142b8f1c001ecde06b
CKSUMS+=	03be8ae293b713fe6e9703e4809dd68caaec992bae6777914ffddae8da2a9bc7

CKSUM_CRATES+=	vendor/crossbeam-utils
CKSUMS+=	c291992d273abba165579ada7873c34ce4f3674363a7c1ec092be856beac0355
CKSUMS+=	63f1cd23943d58f217afa37a0760ede63d6b51a67e886d3c69819103955d3cb3

CKSUM_CRATES+=	vendor/openssl-src
CKSUMS+=	683c9ed1a7953f7f9da43412010de95ba733860a18bc28a4fc3cbcc6ac93c4d7
CKSUMS+=	d83220880699d6a4d9a4e265d19b7896ca4dc7235e3e2f546c5fa06222bdc258
CKSUMS+=	090744f85cf99a9b8412c23fca1eabb61eb45d830f0f9f0e7309be2572c1e827
CKSUMS+=	ead7bdeee121f1357b99741b175a564c8b7026f694cbc388aae2a86b3bae913f

CKSUM_CRATES+=	vendor/nix
CKSUMS+=	c3e13a2edea54d190a4b051f62efc97953c00b5051a9fda0e39e3bc732a31939
CKSUMS+=	263bd7ace66a4cfee3de18532f61c187327fcbd564666b4f97c4b01ae6885d98

CKSUM_CRATES+=	vendor/crossbeam-utils-0.8.14
CKSUMS+=	3314524d2afa0360c947455a6e6566fb54ebf909c99479ca3b7435741fd3293e
CKSUMS+=	eaef167dea04efa811cf0d53de98feac6063ec2196eccd315d345ef86c551aaa

SUBST_CLASSES+=		cksum
SUBST_STAGE.cksum=	pre-configure
.for crate in ${CKSUM_CRATES}
SUBST_FILES.cksum+=	${crate}/.cargo-checksum.json
.endfor
.for from to in ${CKSUMS}
SUBST_SED.cksum+=	-e 's,${from},${to},g'
.endfor

post-extract:
	set -e;									\
	if ${TEST} -e ${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH}/install.sh	\
	  -a ! -e ${RUST_BOOTSTRAP_PATH}/bin/rustc; then \
		cd ${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH};	\
		env ${MAKE_ENV} ${TOOLS_BASH} \
			./install.sh --prefix=${RUST_BOOTSTRAP_PATH};	\
		cd ${WRKDIR}/rust-std-${RUST_STAGE0_VER}-${RUST_ARCH};	\
		env ${MAKE_ENV} ${TOOLS_BASH} \
			./install.sh --prefix=${RUST_BOOTSTRAP_PATH};	\
	fi
.if ${OPSYS} == "NetBSD"
	SDIR=${WRKDIR}/scripts; \
	${MKDIR} $${SDIR}; \
	cd $${SDIR}; \
	${RM} -f c++-wrap; \
	${RM} -f clang++-wrap; \
	${RM} -f clang-wrap; \
	${RM} -f ar-wrap; \
	${CP} ${.CURDIR}/files/gcc-wrap .; \
	${CHMOD} +x gcc-wrap; \
	${LN} -s gcc-wrap c++-wrap; \
	${LN} -s gcc-wrap clang++-wrap; \
	${LN} -s gcc-wrap clang-wrap; \
	${LN} -s gcc-wrap ar-wrap
.endif

.if ${OPSYS} == "FreeBSD"
MAKE_ENV+=		OPENSSL_DIR=${SSLBASE}
.endif

.if ${OPSYS} == "NetBSD" && !empty(PKGSRC_COMPILER:Mclang) && !exists(/lib/libgcc_s.so)
BUILDLINK_TRANSFORM+=	rm:-lgcc_s
MAKE_ENV+=		PKGSRC_HAVE_LIBCPP=yes

pre-build: provide-libgcc-for-bootstrap
.PHONY: provide-libgcc-for-bootstrap
provide-libgcc-for-bootstrap:
.  if exists(${FILESDIR}/libgcc_s.so.1)
	cp ${FILESDIR}/libgcc_s.so.1 ${RUST_BOOTSTRAP_PATH}/lib/.
.  endif
.endif

#
# These are essentially copies of the "all", "test", and "install" Makefile
# targets, but are duplicated here so that we can specify -j.
#
do-build:
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC} &&							\
	${SETENV} ${MAKE_ENV}						\
	sh -c "if [ \"${BUILD_TARGET}\" = \"dist\" ]; then		\
		unset DESTDIR;						\
		${PYTHONBIN} ./x.py -v					\
		    ${BUILD_TARGET} -j ${_MAKE_JOBS_N};			\
	else								\
		${PYTHONBIN} ./x.py -v					\
		    ${BUILD_TARGET} --stage 2 -j ${_MAKE_JOBS_N} &&	\
		${PYTHONBIN} ./x.py -v					\
		    doc --stage 2 -j ${_MAKE_JOBS_N};			\
	fi"

do-test:
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC} &&							\
	${SETENV} ${MAKE_ENV}						\
		${PYTHONBIN} ./x.py -v test -j ${_MAKE_JOBS_N}

do-install:
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC} &&							\
	${SETENV} ${MAKE_ENV} ${INSTALL_ENV} 				\
		${PYTHONBIN} ./x.py -v install -j ${_MAKE_JOBS_N}

GENERATE_PLIST+=	${FIND} ${DESTDIR}${PREFIX} \( -type f -o -type l \) -print | \
			${SED} -e 's,${DESTDIR}${PREFIX}/,,' | ${SORT} ;

# Create a relocatable stage2 bootstrap from the bits we just built that can be
# used to build the next version of rust.  Currently only tested on SmartOS.
#
# Use the alternate BOOTSTRAP_NAME when creating a nightly release.
#
#BOOTSTRAP_NAME=	${PKGNAME_NOREV:C/rust/rust-nightly/}-${RUST_ARCH}
BOOTSTRAP_NAME=		${PKGNAME_NOREV}-${RUST_ARCH}
BOOTSTRAP_TMPDIR=	${WRKDIR}/${BOOTSTRAP_NAME}
USE_TOOLS+=		gtar

# The NetBSD part is so far untested, because I could not convince
# the rust build to use the gcc wrapper when building natively,
# so that I could get a placeholder in the RPATH, because chrpath
# cannot extend the length of the RPATH...
ELFEDIT?=	/usr/bin/elfedit

.PHONY: stage0-bootstrap
stage0-bootstrap: install
	${RM} -rf ${BOOTSTRAP_TMPDIR}
	${MKDIR} ${BOOTSTRAP_TMPDIR}
.if ${OPSYS} == "NetBSD"
	(cd ${BOOTSTRAP_TMPDIR}; \
	DISTDIR=${WRKSRC}/bild/dist; \
	VER_ARCH=${PKGVERSION}-${RUST_ARCH}; \
	RUSTC=rustc-$${VER_ARCH}; \
	RUSTC_FILE=$${RUSTC}.tar.gz; \
	RUST_STD=rust-std-$${VER_ARCH}; \
	RUST_STD_FILE=$${RUST_STD}.tar.gz; \
	${GTAR} -xzf $${DISTDIR}/$${RUSTC_FILE}; \
		(cd ${RUSTC}; \
	RPATH='/usr/pkg/lib:/lib:/usr/lib:$$ORIGIN/../lib'; \
	for f in rls-preview/bin/rls rustc/bin/rustc rustc/bin/rustdoc; do \
		chrpath -r $$RPATH $$f; \
	done; \
	RPATH='/usr/pkg/lib:/lib:/usr/lib:$$ORIGIN'; \
	for f in rustc/lib/*.so*; do \
		chrpath -r $$RPATH $$f; \
	done; \
	RPATH='/usr/pkg/lib:/lib:/usr/lib:$$ORIGIN:$$ORIGIN/../../..'; \
	for f in rustc/lib/rustlib/*/*/*.so*; do \
		chrpath -r $$RPATH $$f; \
	done;); \
	${GTAR} -czf $${RUSTC_FILE} $${RUSTC}; \
	${CP} $${DISTDIR}/$${RUST_STD_FILE} .; \
	${ECHO} "Fixed stage0 bootstrap in ${BOOTSTRAP_TMPDIR}:"; \
	${ECHO} "$${RUSTC_FILE}"; \
	${ECHO} "$${RUST_STD_FILE}"; \
	)
.endif
.if ${OS_VARIANT} == "SmartOS"
	${CP} -R ${DESTDIR}/${PREFIX}/bin ${BOOTSTRAP_TMPDIR}/
	${CP} -R ${DESTDIR}/${PREFIX}/lib ${BOOTSTRAP_TMPDIR}/
	${MKDIR} ${BOOTSTRAP_TMPDIR}/lib/pkgsrc
	set -e; \
	for lib in libgcc_s.so.1 libstdc++.so.6; do \
		${CP} `${PKG_CC} -print-file-name=$${lib}` \
		    ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/; \
	done; \
	for lib in libLLVM-15.so libcrypto.so.1.1 libcurl.so.4 \
		   libssl.so.1.1 libz.so.1 libzstd.so.1; do \
		${CP} ${PREFIX}/lib/$${lib} ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/; \
	done; \
	for lib in libiconv.so.2 libidn2.so.0 libintl.so.8 liblber.so.2 \
		   libldap.so.2 libnghttp2.so.14 libsasl2.so.3 \
		   libssh2.so.1 libunistring.so.5; do \
		${CP} ${PREFIX}/lib/$${lib} ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/; \
	done; \
	for f in ${BOOTSTRAP_TMPDIR}/bin/*; do \
		/bin/file -b "$$f" | grep ^ELF >/dev/null || continue; \
		${ELFEDIT} -e 'dyn:runpath $$ORIGIN/../lib:$$ORIGIN/../lib/pkgsrc' $$f; \
	done; \
	for f in ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/*.so*; do \
		${ELFEDIT} -e 'dyn:runpath $$ORIGIN' $$f; \
	done; \
	for f in ${BOOTSTRAP_TMPDIR}/lib/*.so*; do \
		${ELFEDIT} -e 'dyn:runpath $$ORIGIN:$$ORIGIN/pkgsrc' $$f; \
	done; \
	for f in ${BOOTSTRAP_TMPDIR}/lib/rustlib/*/*/*.so*; do \
		${ELFEDIT} -e 'dyn:runpath $$ORIGIN:$$ORIGIN/../../..:$$ORIGIN/../../../pkgsrc' $$f; \
	done; \
	cd ${WRKDIR}; ${GTAR} -zcf ${BOOTSTRAP_NAME}.tar.gz ${BOOTSTRAP_NAME}
	@${ECHO} ""
	@${ECHO} "Verify correct library paths using the following:"
	@${ECHO} ""
	@${ECHO} "	cd ${BOOTSTRAP_TMPDIR}"
	@${ECHO} "	find . -type f | xargs ldd 2>/dev/null | egrep 'not.found|${PREFIX}'"
	@${ECHO} ""
	@${ECHO} "If there is no output then this bootstrap kit is ready to go:"
	@${ECHO} ""
	@${ECHO} "	${WRKDIR}/${BOOTSTRAP_NAME}.tar.gz"
	@${ECHO} ""
.endif

.include "options.mk"

# These dependencies currently use the bundled sources as they require
# development features not yet available in released versions.
#
#.include "../../devel/libgit2/buildlink3.mk"
#.include "../../security/libssh2/buildlink3.mk"
#.include "../../www/http-parser/buildlink3.mk"
#.include "../../devel/jemalloc/buildlink3.mk"

## Issues specific to: bootstrap AND NetBSD follow

# rust i386 and sparc64 bootstraps are built for 8.0
# and still depend on libstdc++.so.8.
# Pull in compat80 on 9.x and newer.
.if (${MACHINE_PLATFORM:MNetBSD-*-i386} || \
     ${MACHINE_PLATFORM:MNetBSD-*-sparc64}) \
    && empty(OS_VERSION:M8.*)
TOOL_DEPENDS+=	compat80>=0:../../emulators/compat80
.endif

.include "../../mk/atomic64.mk"
# This is for when we build natively:
.if ${MACHINE_PLATFORM:MNetBSD-*-powerpc} || \
    ${MACHINE_PLATFORM:MNetBSD-*-i386} || \
    ${MACHINE_PLATFORM:MNetBSD-*-mipsel}
# Make libatomic library available via a unique directory:
DEPENDS+=	libatomic-links>=0:../../devel/libatomic-links
.endif

TOOL_DEPENDS+= cmake-[0-9]*:../../devel/cmake
.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
