# $NetBSD: cross.mk,v 1.10 2023/01/23 18:49:03 he Exp $

# These settings may be used to cross-build rust.
#
# They interact with the files/gcc-wrap script to pick the
# right compiler for the different phases of the build, and
# use the headers for the target when required.  Note that the
# cross-root tree will need to have the required binary packages
# installed (curl etc., see list of buildlink3.mk includes in main
# Makefile).

# The gcc-wrap / c++-wrap script takes CROSS_ROOT environment variable
# to do a cross-build.  The wrapper script assumes dest/ and tools/
# as a result of a cross-build of NetBSD as subdirectories of this root
#CROSS_ROOT=		/u/evbarm-armv7hf
#CROSS_ROOT=		/u/evbarm-armv6hf
#CROSS_ROOT=		/u/sparc64
#CROSS_ROOT=		/u/macppc
#CROSS_ROOT=		/u/9.0-macppc
#CROSS_ROOT=		/u/evbarm64
#CROSS_ROOT=		/u/evbarm64eb
#CROSS_ROOT=		/u/i386
#CROSS_ROOT=		/u/mipsel
#CROSS_ROOT=		/
#MAKE_ENV+=		CROSS_ROOT=${CROSS_ROOT}

# The GNU cross target designation
#GNU_CROSS_TARGET=	armv7--netbsdelf-eabihf
#GNU_CROSS_TARGET=	armv6--netbsdelf-eabihf
#GNU_CROSS_TARGET=	sparc64--netbsd
#GNU_CROSS_TARGET=	powerpc--netbsd
#GNU_CROSS_TARGET=	aarch64--netbsd
#GNU_CROSS_TARGET=	aarch64_be--netbsd
#GNU_CROSS_TARGET=	i486--netbsdelf
#GNU_CROSS_TARGET=	mipsel--netbsd
#MAKE_ENV+=		GNU_CROSS_TARGET=${GNU_CROSS_TARGET}

# To cross-build rust, you need to specify
# the ultimate target to built for, as well as the
# host the compiler is supposed to run on.
# Rust's target designation
#TARGET=		armv7-unknown-netbsd-eabihf
#TARGET=		armv6-unknown-netbsd-eabihf
#TARGET=		sparc64-unknown-netbsd
#TARGET=		powerpc-unknown-netbsd
#TARGET=		aarch64-unknown-netbsd
#TARGET=		aarch64_be-unknown-netbsd
#TARGET=		i686-unknown-netbsd
#TARGET=		i586-unknown-netbsd
#TARGET=		mipsel-unknown-netbsd
#
#SCRIPTS=		${WRKDIR}/scripts
#CONFIGURE_ARGS+=	--host=${TARGET}
#CONFIGURE_ARGS+=	--target=${TARGET}
#CONFIGURE_ARGS+=	--set=target.${TARGET}.cc=${SCRIPTS}/gcc-wrap
#CONFIGURE_ARGS+=	--set=target.${TARGET}.cxx=${SCRIPTS}/c++-wrap
#CONFIGURE_ARGS+=	--set=target.${TARGET}.linker=${SCRIPTS}/gcc-wrap
# Pick one:
#CONFIGURE_ARGS+=	--set=target.${TARGET}.ar=${CROSS_ROOT}/tools/bin/${GNU_CROSS_TARGET}-ar
#CONFIGURE_ARGS+=	--set=target.${TARGET}.ar=${SCRIPTS}/ar-wrap

# May be required when cross-building on NetBSD
#MAKE_ENV+=		OPENSSL_DIR=/usr

#
# Cross-compile illumos target.  The host is identical, it's just the target
# that is renamed from x86_64-sun-solaris to x86_64-unknown-illumos.
#
#TARGET=		x86_64-unknown-illumos
#
# Use these variables for "cross-compiling" from x86_64-sun-solaris.
#
#CONFIGURE_ARGS+=	--set=target.${TARGET}.llvm-config=${LLVM_CONFIG_PATH}
#CONFIGURE_ARGS+=	--host=${TARGET}
#CONFIGURE_ARGS+=	--target=${TARGET}
#
# Set this variable when using a native x86_64-unknown-illumos bootstrap, as
# the build still defaults to x86_64-sun-solaris based on uname.
#
#CONFIGURE_ARGS+=	--build=${TARGET}
