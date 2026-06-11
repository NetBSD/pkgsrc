# $NetBSD: Makefile,v 1.361 2026/06/11 07:00:56 wiz Exp $

DISTNAME=	rustc-1.96.0-src
PKGNAME=	${DISTNAME:S/rustc/rust/:S/-src//}
CATEGORIES=	lang
MASTER_SITES=	https://static.rust-lang.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

CONFLICTS+=	rust-bin-[0-9]*

# LLVM uses -std=c++17
USE_CXX_FEATURES+=	c++17
USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bash grep gmake perl:build pkg-config

# This is a bug:
#   https://github.com/rust-lang/rust/issues/130708
# "Building rust 1.81.0 does network access in the "build" phase"
# but set it for now to allow progress in finding other build issues.
#ALLOW_NETWORK_ACCESS=	yes
# Ref. dist.vendor below.

# The NetBSD bootstraps are built for NetBSD 9 (because rust doesn't
# build on 8 or earlier), or because the target didn't exist in 8
# or 9 (as in riscv64).  Therefore, mark earlier versions as broken.
BROKEN_ON_PLATFORM+=	NetBSD-[1-8].*-*

HAS_CONFIGURE=		yes
PYTHON_FOR_BUILD_ONLY=	tool
CONFIG_SHELL=		${TOOL_PYTHONBIN}
CONFIGURE_SCRIPT=	src/bootstrap/configure.py
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--python=${TOOL_PYTHONBIN}
CONFIGURE_ARGS+=	--release-channel=stable
CONFIGURE_ARGS+=	--local-rust-root=${RUST_BOOTSTRAP_PATH}
CONFIGURE_ARGS+=	--enable-extended	# Build and install cargo too.
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--disable-codegen-tests
CONFIGURE_ARGS+=	--disable-compiler-docs
CONFIGURE_ARGS+=	--disable-llvm-static-stdcpp
CONFIGURE_ARGS+=	--disable-ninja
CONFIGURE_ARGS+=	--dist-compression-formats=xz
# Ref. issue #130708 & backport of pull-request 130110
CONFIGURE_ARGS+=	--set dist.vendor=false

CGC=			compiler/rustc_codegen_cranelift
REPLACE_BASH+=		${CGC}/.github/scripts/free-disk-space.sh
REPLACE_BASH+=		library/portable-simd/subtree-sync.sh
CB=			library/compiler-builtins
REPLACE_BASH+=		${CB}/ci/bench-icount.sh
REPLACE_BASH+=		${CB}/ci/miri.sh
REPLACE_BASH+=		${CB}/ci/run-docker.sh
REPLACE_BASH+=		${CB}/ci/run-extensive.sh
REPLACE_BASH+=		${CB}/ci/run.sh

REPLACE_PYTHON+=	${CB}/ci/ci-util.py
REPLACE_PYTHON+=	${CB}/etc/update-api-list.py

# Include (optional) settings to cross-build rust
.include "cross.mk"

# optional from do-cross.mk
CONFIGURE_ARGS+=	${ADD_CONFIGURE_ARGS}

# This should allow us to perform "offline" builds (so cargo doesn't fetch
# dependencies during the build stage) but this isn't hooked up yet.
CONFIGURE_ARGS+=	--enable-vendor

# cargo defaults to using the number of available CPUs
MAKE_ENV+=		CARGO_BUILD_JOBS=${_MAKE_JOBS_N}

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS
MAKE_ENV.SunOS+=	AR=gar
MAKE_ENV.SunOS+=	BOOTSTRAP_SKIP_TARGET_SANITY=1

# Debugging of crate resolution
# Annoyingly, this makes the powerpc build succeed...
#MAKE_ENV+=		RUSTC_LOG=rustc_metadata

UNLIMIT_RESOURCES+=	cputime stacksize datasize virtualsize

TEST_TARGET=	check

# bin/* lib/*, but names vary
CHECK_RELRO_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# Getting RPATH with $ORIGIN into the bootstrap binaries is
# problematic, since pkgsrc refuses to put $ORIGIN into RPATHs
# of executables. So instead we need these so that the bootstrap
# compiler can be run out of the $RUST_BOOTSTRAP_PATH directory as
# part of the initial part of the rust compiler build.
# This problem is not present with the amd64 bootstrap bits,
# which are built by our upstream and uses $ORIGIN/../lib in RPATH.
#
# The above is only true on NetBSD, for other bootstrap kits (e.g. illumos)
# the binaries are made to be relocatable after the build using elfedit or
# similar.  It is unclear why this approach is not used by NetBSD too.
#
MAKE_ENV+=		LD_LIBRARY_PATH=${RUST_BOOTSTRAP_PATH:Q}/lib
PKGSRC_MAKE_ENV+=	LD_LIBRARY_PATH=${RUST_BOOTSTRAP_PATH:Q}/lib
.endif

# TODO: Hack introduced for 1.86.0 as @loader_path is stripped from the
# bootstrap compiler arguments and the stage1 libraries cannot be found.
# Ideally this should be inserted only in the necessary points of the
# bootstrap script.
.if ${OPSYS} == "Darwin"
MAKE_ENV+=	DYLD_LIBRARY_PATH="${WRKSRC}/build/${MACHINE_ARCH}-apple-darwin/stage1/lib:${WRKSRC}/build/${MACHINE_ARCH}-apple-darwin/stage2/lib"
.endif

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

RUSTLIB_COMPILER=	lib/rustlib/rustc-src/rust/compiler
RUSTC_CG_CRANELIFT=	${RUSTLIB_COMPILER}/rustc_codegen_cranelift

CHECK_INTERPRETER_SKIP+=	${RUSTC_CG_CRANELIFT}/scripts/filter_profile.rs
CHECK_INTERPRETER_SKIP+=	${RUSTC_CG_CRANELIFT}/scripts/rustup.sh
CHECK_INTERPRETER_SKIP+=	${RUSTC_CG_CRANELIFT}/scripts/test_bootstrap.sh
CHECK_INTERPRETER_SKIP+=	${RUSTC_CG_CRANELIFT}/scripts/test_rustc_tests.sh
CHECK_INTERPRETER_SKIP+=	${RUSTLIB_COMPILER}/rustc_codegen_gcc/y.sh
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/backtrace/ci/*.sh
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/core/src/unicode/printable.py
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/stdarch/ci/*.sh
CHECK_PORTABILITY_SKIP+=	tests/run-make/dump-ice-to-disk/check.sh
CHECK_PORTABILITY_SKIP+=	vendor/libdbus-sys-0.2.5/vendor/dbus/tools/cmake-format

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
.  if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} > 090999 && ${OPSYS_VERSION} < 090900
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
RUST_STAGE0_VER=	1.95.0
RUST_ARCH:=		aarch64-apple-darwin
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MDarwin-*-x86_64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.95.0
RUST_ARCH:=		x86_64-apple-darwin
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MLinux-*-aarch64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.95.0
RUST_ARCH:=		aarch64-unknown-linux-gnu
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MLinux-*-earmv6hf} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.95.0
RUST_ARCH:=		arm-unknown-linux-gnueabihf
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MLinux-*-earmv7hf} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.95.0
RUST_ARCH:=		armv7-unknown-linux-gnueabihf
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MLinux-*-i386} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.95.0
RUST_ARCH:=		i686-unknown-linux-gnu
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MLinux-*-x86_64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.95.0
RUST_ARCH:=		x86_64-unknown-linux-gnu
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MSunOS-*-x86_64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.95.0
RUST_ARCH:=		x86_64-unknown-illumos
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
# Override default "x86_64-sun-solaris" selection
CONFIGURE_ARGS+=	--set=target.${RUST_ARCH}.llvm-config=${LLVM_CONFIG_PATH}
CONFIGURE_ARGS+=	--build=${RUST_ARCH}
CONFIGURE_ARGS+=	--host=${RUST_ARCH}
CONFIGURE_ARGS+=	--target=${RUST_ARCH}
.endif
.if ${MACHINE_PLATFORM:MFreeBSD-*-x86_64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.95.0
RUST_ARCH:=		x86_64-unknown-freebsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-i386} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.95.0
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
RUST_STAGE0_VER=	1.95.0
RUST_ARCH=		x86_64-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-powerpc} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=		1.95.0
RUST_ARCH=			powerpc-unknown-netbsd
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=		1.95.0
RUST_ARCH=			aarch64-unknown-netbsd
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64eb} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=		1.95.0
RUST_ARCH=			aarch64_be-unknown-netbsd
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-sparc64} || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=		1.95.0
RUST_ARCH=			sparc64-unknown-netbsd
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-earmv7hf} || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH=			armv7-unknown-netbsd-eabihf
RUST_STAGE0_VER=		1.95.0
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-earmv6hf} || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH=			armv6-unknown-netbsd-eabihf
RUST_STAGE0_VER=		1.95.0
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.endif
#.if ${MACHINE_PLATFORM:MNetBSD-*-mipsel} || make(distinfo) || make (makesum) || make(mdi)
#RUST_ARCH=			mipsel-unknown-netbsd
#RUST_STAGE0_VER=		1.95.0
#RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
#RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
#DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
#SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
#SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
#.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-riscv64} || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH=			riscv64gc-unknown-netbsd
RUST_STAGE0_VER=		1.95.0
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
TOOLS_PATH.md5sum=	${TOOLBASE}/bin/gmd5sum
TOOLS_PLATFORM.gzcat=	${TOOLBASE}/bin/gzip -cd
.endif

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	compiler/rustc_codegen_ssa/src/back/linker.rs
SUBST_FILES.prefix+=	compiler/rustc_target/src/spec/base/netbsd.rs
SUBST_FILES.prefix+=	src/bootstrap/src/core/build_steps/compile.rs
SUBST_FILES.prefix+=	src/bootstrap/src/core/builder/cargo.rs
SUBST_FILES.prefix+=	src/bootstrap/bootstrap.py
SUBST_VARS.prefix=	PREFIX

#
# Generate list of subst entries for various .cargo-checksum.json files.  These
# are all handled together in one big substitution to simplify things rather
# than one substitution entry per file, but are kept separate below to ease
# updating and verification.
#

CKSUM_CRATES+=	vendor/crossbeam-utils-0.8.18
CKSUMS+=	31a8276afd38e39987a169eeb02e9bed32670de5ca36d7eb74aab7e506cf9dc4
CKSUMS+=	ead4bda23c322bde8c01e48d4cd19b70e7b7e473a56466218d279f88463ab466

CKSUM_CRATES+=	vendor/openssl-src-300.5.0+3.5.0
CKSUMS+=	16c0b9fa70475cfb50ac21ad4ce049b494c45b3270fed386013785a28abb8d0a
CKSUMS+=	e2817c457afa7efc0f2ca62ce9dab5254eb5ddd9a5fd9e75bba2789be92c7b14
CKSUMS+=	6e62515e67910aea2f04b64c643aa2545732f9dd7bf0abf87d8accf8c2c1fb88
CKSUMS+=	ccc5252660386fbfec2d66423f2dc87e6da74efd39ca0fcd7c7fd583056725c1
CKSUMS+=	ac5501e7bff0f4384db0537307b362bf1bcb120d8b5859e5f08bd796e78feaea
CKSUMS+=	6d2c2831119e059d35e81a89b08195a29e325f68acfd86a3a7157ebf8e78182d

CKSUM_CRATES+=	vendor/openssl-src-300.5.4+3.5.4
CKSUMS+=	33f1e78110293a8558ae997ed57e7aac72c5bfd47a241dc7f6e2ffa98b7a7137
CKSUMS+=	d0232a8b63c2fb396ed7551eb983b16b6ebafbba4b33d4434e167b05ee290f8f
# covered by 3.5.0:
#CKSUMS+=	6e62515e67910aea2f04b64c643aa2545732f9dd7bf0abf87d8accf8c2c1fb88
#CKSUMS+=	ccc5252660386fbfec2d66423f2dc87e6da74efd39ca0fcd7c7fd583056725c1
#CKSUMS+=	ac5501e7bff0f4384db0537307b362bf1bcb120d8b5859e5f08bd796e78feaea
#CKSUMS+=	6d2c2831119e059d35e81a89b08195a29e325f68acfd86a3a7157ebf8e78182d

#CKSUM_CRATES+=	vendor/openssl-sys-0.9.92
#CKSUMS+=
#CKSUMS+=

CKSUM_CRATES+=	vendor/openssl-sys-0.9.107
CKSUMS+=	a0d47c624273b43b4250cff5fa2f9b75e4199ca76897608563b526aedcdf3a16
CKSUMS+=	fcfc15ca30e1f881ed46cf57597a72bd2a8307269d0394c905f23e076a983e12
CKSUMS+=	e6d478786035538d721d88b7736f602c965a38687a805cb377ebbe0ea1a14617
CKSUMS+=	e2b2473bdf7ce5f854fcef6f07f984accc53b4382dba160d625c1fcbaba31612

CKSUM_CRATES+=	vendor/openssl-sys-0.9.109
CKSUMS+=	112fcb6f18b81f31c23c60e7be5fddc87603c05a595f2e22b6e8f7ed2ea89e5f
CKSUMS+=	023a3e755d7d4c5ca6e4f8ce7a8b1dc2dd1e50cbfcaa43cc6fe809b251ee7037
CKSUMS+=	f66ce762ec63c28621a0d6d48bd5872b96e71f0bfb6f88576a6e2cba0c229e12
CKSUMS+=	656834a8bd87476b074f36bcc2aeb33a74a0a0a6db5d140c35c4b3eb385afebe

CKSUM_CRATES+=	vendor/openssl-sys-0.9.111
CKSUMS+=	0c5a4bd38ed007182cfec3cf0824a4806e5c629b9d69e3cc2a5b6e9be3eec280
CKSUMS+=	777a22f3cd39ad01f2e559ecf600bb9c03ec42e0b9fbe41746f42938e162d523
CKSUMS+=	d17fa8715a43ff0da872ac504abb2cc0a395644e8f5c8c128812758c458d5963
CKSUMS+=	02d5de4e4976450f8e665e0eff664e93063dd53aec2cb75ecee0847e3c0c086e

CKSUM_CRATES+=	vendor/openssl-sys-0.9.112
CKSUMS+=	342928b9516d20cf21850581af2377fe2d8f67c15da645d106fc83fc30395623
CKSUMS+=	bea5102ee4a0de3233653ded97be49ba8e190afdb056ab794e8947a84e183ce0
CKSUMS+=	0c5a4bd38ed007182cfec3cf0824a4806e5c629b9d69e3cc2a5b6e9be3eec280
CKSUMS+=	777a22f3cd39ad01f2e559ecf600bb9c03ec42e0b9fbe41746f42938e162d523

CKSUM_CRATES+=	vendor/libc-0.2.155
CKSUMS+=	3e550d95419169febf094c425451ca86b12821fa17839b4b0ba7520b145a5820
CKSUMS+=	1cf38d9ddeca5295821b4234e17e1fc749f35b00307bdfdacb24c6892a288ad6
CKSUMS+=	b8d6f089fc8eb2cb59e45335a26c9ce871b846216c9859b553c6b91982f8de33
CKSUMS+=	d8c4a979ce9b406fb63c5aaf2827b616689294331341737fec392b8faa2126fa

CKSUM_CRATES+=	vendor/libc-0.2.169
CKSUMS+=	dc216609dfc6b2835e26f8c3e70f4c7c65425933eef04538de603f51e9429ec5
CKSUMS+=	04004bda0ea97d55c3588a7d82fa1faf0d150c5390250a298216ff3cc899b911
CKSUMS+=	b5dae853ebfc3355b155f8c20f3a481517bce27e164e304f56dfff172e313098
CKSUMS+=	55fb7f2c0877231286b2b6515e08eda1d5cac1311a402d0aa162c7eb867ee19b
CKSUMS+=	0b1936bad97b3a272c2d323d3435f6860fc355abe7603ca7ed8c4166cac75cc5
CKSUMS+=	1eb383a057cdf2826d884b19142bf0b68b6b30c5bc20baf7ee10401a92a8ef22

CKSUM_CRATES+=	vendor/libc-0.2.171
CKSUMS+=	f3778a9bd2ba923220537d167cfb10b91580ffbf583100789a46d2807f7a1e3e
CKSUMS+=	2dc054435fd2976536b6685d66ba6796d4eb143885bd573e686e9b042ae7257a
CKSUMS+=	27feafe043662f005d622502fbb31d99877c1ed8d83b30f350dafcdb513fee69
CKSUMS+=	2dc054435fd2976536b6685d66ba6796d4eb143885bd573e686e9b042ae7257a

CKSUM_CRATES+=	vendor/libc-0.2.172
CKSUMS+=	ec4c1dce83e8531df71b89e4aee1ab4d3b3b18d1b6d34b03d94573144c40e7c5
CKSUMS+=	dc3179a14c65c5e3d250ce9819934236f11fc6c9bfa7afa8d4208931d28e4250
CKSUMS+=	f3778a9bd2ba923220537d167cfb10b91580ffbf583100789a46d2807f7a1e3e
CKSUMS+=	2dc054435fd2976536b6685d66ba6796d4eb143885bd573e686e9b042ae7257a

CKSUM_CRATES+=	vendor/libc-0.2.174
CKSUMS+=	f3778a9bd2ba923220537d167cfb10b91580ffbf583100789a46d2807f7a1e3e
CKSUMS+=	2dc054435fd2976536b6685d66ba6796d4eb143885bd573e686e9b042ae7257a
CKSUMS+=	27feafe043662f005d622502fbb31d99877c1ed8d83b30f350dafcdb513fee69
CKSUMS+=	2dc054435fd2976536b6685d66ba6796d4eb143885bd573e686e9b042ae7257a

CKSUM_CRATES+=	vendor/libc-0.2.175
CKSUMS+=	efa1a156cff1ab2450439adbb3ab2113bed6b7de2205c99e9cba875aa2b1c153
CKSUMS+=	f446c996f00e4d15fd25461a30c767c05d083df9e047b0da497ce7c545acfa96
CKSUMS+=	40c61bfb238ba988391cabe55e389c33e7adce7cf1cdd8a6db56406401f566e3
CKSUMS+=	65fe8c348242f176decd9c71be8dfce0baa005e7cb0cab2f3d2a05dae2593ecd

CKSUM_CRATES+=	vendor/libc-0.2.177
# covered by libc-0.2.175
#CKSUMS+=	efa1a156cff1ab2450439adbb3ab2113bed6b7de2205c99e9cba875aa2b1c153
#CKSUMS+=	f446c996f00e4d15fd25461a30c767c05d083df9e047b0da497ce7c545acfa96
CKSUMS+=	461feb5dc8dddea353ab6d32519045bc9f16525a48449c93dc7148469d94c9c3
CKSUMS+=	1cab8d313161004e10463c6fd37c0846b31dbb7ccd0dbb509dd4e3edd94dda5b

CKSUM_CRATES+=	vendor/libc-0.2.180
CKSUMS+=	7628a61b5d75750047eb9cb79d0dc89d45cf0cf32edc5786cf7ca45c5dab1114
CKSUMS+=	85ab34c72fc39f2c5a5cf98aebe896e6629f8b53f0592dde614f22b2b271fc5a

CKSUM_CRATES+=	vendor/libc-0.2.183
CKSUMS+=	a782d53bc9e06c87c6c8b8182ee79cab693ce39be7d9ecb9dcd7ca285284734f
CKSUMS+=	2113dd4a3bdacf81fc125eb14b6e42d34e79c7df8909ace69c41e639bea51b4f

CKSUM_CRATES+=	vendor/libc-0.2.184
CKSUMS+=	12d1e288aa3c351000721502e3cbd7115d7d5584ffc5c37f5c00e9c56f657385
CKSUMS+=	ba90b1b54ba7ec1368ade4eeebc5a6ac0f43aa2468ace5601b3a2d64b8b2e3af

CKSUM_CRATES+=	vendor/zerocopy-0.7.32
CKSUMS+=	2f21f18a4ca1d4be2d997f037158cb21a7421b2ba2cc52f3e4c5f9410197ed27
CKSUMS+=	abe079743c2b2dea5b2c42564f98741a5eb9e24ff019e01742ace5581e53c06f

CKSUM_CRATES+=	vendor/zerocopy-0.7.35
CKSUMS+=	eb5033d1f2f3d5314625bc63353b1d105cb414d4bc68edf8700b401e4055d669
CKSUMS+=	bd504cc95f722a296a5f221c3a3068c9eaa946258beff163581d9492de6ccdce

CKSUM_CRATES+=	vendor/memchr-2.7.4
CKSUMS+=	5bb70f915084e629d940dbc322f5b9096b2e658cf63fea8a2f6e7550412e73a0
CKSUMS+=	34aaa34eb7048e8bba49d390942ab707990380952f37f388f3cca30970c53450
CKSUMS+=	7763472d43c66df596ca0697c07db0b4666d38a6a14f64f9f298aaf756c4a715
CKSUMS+=	1b26fca824c410077780fbc2f4c53c1d195ba3bdf6785b529ceb0a11f039cec2
CKSUMS+=	3b15d5cb9715f26e655598eacbb8bbba74cbe8ddb2fb969d13aa75f216a118dd
CKSUMS+=	8844a2cd5e71abb8efdf8fc3ee54d9c66f3fedb529cdaf5984c279177f5f90af
CKSUMS+=	6ae779ec5d00f443075316e0105edf30b489a38e2e96325bec14ccecd014145b
CKSUMS+=	28d66e566b73f6f0f7add4092874dc967ce133bfb6dcbd81f03c9a04b6e4e1d0
CKSUMS+=	44cd1a614bd66f1e66fc86c541d3c3b8d3a14a644c13e8bf816df3f555eac2d4
CKSUMS+=	27f9bff08b24828e1a611b10a0282f5457d12e9e7254202040144d392297d720

CKSUM_CRATES+=	vendor/line-index-0.1.2
CKSUMS+=	c4613b718951cf0b880a3a7829e102a9ec7196591437e3bc0cfd857c717bfb61
CKSUMS+=	5183e802793932fb980b4e321656c65d1b6231de3febd1ac94dfa73de31245f0

CKSUM_CRATES+=	vendor/lzma-sys-0.1.20
CKSUMS+=	6fd5e9245db34c6f557b8bfcaf03db82fc88c3b06dbfbb5f03b2bcd138983ef9
CKSUMS+=	2a68e3e635dce81c7dba25b3d3abfaa894ee729e1604f2d000ae3e201f7739a4

CKSUM_CRATES+=	vendor/zeroize-1.8.1
CKSUMS+=	9f59308c21265a2fb46935a6468d8bc2e86e4613c9a942fcfc91d61bec8cc878
CKSUMS+=	9e20af81edc96e11f17c3e3a2933c073b6c6f9b86ca25cab0eabd763c6b80aee

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

# Rust builds some bundled components with strict version requirements, ensure
# that any conflicting packages pulled in via dependencies are not buildlinked.
BUILDLINK_FILES_CMD.xz=		${TRUE}
MAKE_ENV+=			LZMA_API_STATIC=1
pre-configure:
	${RM} -rf ${BUILDLINK_DIR}/include/libssh2*

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
		${TOOL_PYTHONBIN} ./x.py				\
		    ${BUILD_TARGET} -j ${_MAKE_JOBS_N};			\
	else								\
		${TOOL_PYTHONBIN} ./x.py				\
		    ${BUILD_TARGET} --stage 2 -j ${_MAKE_JOBS_N} &&	\
		${TOOL_PYTHONBIN} ./x.py				\
		    doc --stage 2 -j ${_MAKE_JOBS_N};			\
	fi"

do-test:
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC} &&							\
	${SETENV} ${MAKE_ENV}						\
		${TOOL_PYTHONBIN} ./x.py test -j ${_MAKE_JOBS_N}

do-install:
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC} &&							\
	${SETENV} ${MAKE_ENV} ${INSTALL_ENV} 				\
		${TOOL_PYTHONBIN} ./x.py install -j ${_MAKE_JOBS_N}
.if ${OPSYS} == "Darwin"
	cd ${DESTDIR}${PREFIX}/lib && \
	for lib in rustlib/*/lib/lib*.${SHLIB_EXT}; do \
		install_name_tool -id ${PREFIX}/lib/$${lib##*/} $${lib}; \
		${LN} -f $${lib} $${lib##*/}; \
	done
.endif

.if ${MACHINE_PLATFORM:MNetBSD-*-i386}
USE_TOOLS+=	paxctl
# Turn off address space layout randomization
# so that we can build firefox natively:
post-install:
	${TOOLS_PLATFORM.paxctl} +a ${DESTDIR}${PREFIX}/bin/rustc
.endif

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	post-install
SUBST_FILES.destdir=	${DESTDIR}${PREFIX}/lib/rustlib/manifest-*
SUBST_SED.destdir=	-e 's|file:${DESTDIR}${PREFIX}|file:${PREFIX}|'

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
	${CP} -R ${DESTDIR}${PREFIX}/bin ${BOOTSTRAP_TMPDIR}/
	${CP} -R ${DESTDIR}${PREFIX}/lib ${BOOTSTRAP_TMPDIR}/
	${MKDIR} ${BOOTSTRAP_TMPDIR}/lib/pkgsrc
	set -e; \
	for lib in libgcc_s.so.1 libstdc++.so.6; do \
		${CP} `${PKG_CC} -print-file-name=$${lib}` \
		    ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/; \
	done; \
	for lib in libLLVM.so.21.1 libcrypto.so.3 libcurl.so.4 \
		   libssl.so.3 libz.so.1 libzstd.so.1; do \
		${CP} ${PREFIX}/lib/$${lib} ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/; \
	done; \
	for lib in libiconv.so.2 libidn2.so.0 libintl.so.8 liblber.so.2 \
		   libldap.so.2 liblzma.so.5 libnghttp2.so.14 libsasl2.so.3 \
		   libssh2.so.1 libunistring.so.5 libxml2.so.16; do \
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
	for f in ${BOOTSTRAP_TMPDIR}/lib/rustlib/*/*/*.so* \
		 ${BOOTSTRAP_TMPDIR}/lib/rustlib/*/bin/* \
		 ${BOOTSTRAP_TMPDIR}/lib/rustlib/*/bin/*/*; do \
		/bin/file -b "$$f" | grep ^ELF >/dev/null || continue; \
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

.include "../../mk/atomic64.mk"
# This is for when we build natively:
.if ${MACHINE_PLATFORM:MNetBSD-*-powerpc} || \
    ${MACHINE_PLATFORM:MNetBSD-*-i386} || \
    ${MACHINE_PLATFORM:MNetBSD-*-mipsel} || \
    ${MACHINE_PLATFORM:MNetBSD-*-riscv64}
# Make libatomic library available via a unique directory:
DEPENDS+=	libatomic-links>=0:../../devel/libatomic-links
.endif

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
