# $NetBSD: options.mk,v 1.1 2020/08/05 06:24:32 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mercurial
PKG_SUPPORTED_OPTIONS=		rust
PKG_SUGGESTED_OPTIONS=		# rust

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	rust

.if !empty(PKG_OPTIONS:Mrust)
PLIST.rust=	yes
PYSETUPARGS+=	--rust
# for python3-sys
MAKE_ENV+=	PYTHON_SYS_EXECUTABLE=${PYTHONBIN}

# When updating:
#	  cd ${WRKSRC}
#	  cat $(find .. -name Cargo.lock) > Cargo.lock
#	  cd -
#	  make show-cargo-depends | sort -u
#
# After updating, check:
#         hg debuginstall | grep -i rust
# to validate rust is in use
#
# Two steps of tests work, but then fail with
# mercurial-5.5/rust/target/debug/deps/rusthg-a55fe645bc4ab58d: Shared object "libpython3.7.so.1.0" not found

CARGO_CRATE_DEPENDS+=	aho-corasick-0.7.10
CARGO_CRATE_DEPENDS+=	ansi_term-0.11.0
CARGO_CRATE_DEPENDS+=	anyhow-1.0.28
CARGO_CRATE_DEPENDS+=	arc-swap-0.4.5
CARGO_CRATE_DEPENDS+=	async-trait-0.1.30
CARGO_CRATE_DEPENDS+=	atty-0.2.14
CARGO_CRATE_DEPENDS+=	autocfg-1.0.0
CARGO_CRATE_DEPENDS+=	bitflags-1.2.1
CARGO_CRATE_DEPENDS+=	byteorder-1.3.4
CARGO_CRATE_DEPENDS+=	bytes-0.5.4
CARGO_CRATE_DEPENDS+=	cc-1.0.50
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.10
CARGO_CRATE_DEPENDS+=	chrono-0.4.11
CARGO_CRATE_DEPENDS+=	clap-2.33.1
CARGO_CRATE_DEPENDS+=	colored-1.9.3
CARGO_CRATE_DEPENDS+=	cpython-0.4.1
CARGO_CRATE_DEPENDS+=	crossbeam-0.7.3
CARGO_CRATE_DEPENDS+=	crossbeam-channel-0.4.2
CARGO_CRATE_DEPENDS+=	crossbeam-deque-0.7.3
CARGO_CRATE_DEPENDS+=	crossbeam-epoch-0.8.2
CARGO_CRATE_DEPENDS+=	crossbeam-queue-0.2.1
CARGO_CRATE_DEPENDS+=	crossbeam-utils-0.7.2
CARGO_CRATE_DEPENDS+=	ctor-0.1.13
CARGO_CRATE_DEPENDS+=	difference-2.0.0
CARGO_CRATE_DEPENDS+=	either-1.5.3
CARGO_CRATE_DEPENDS+=	fs_extra-1.1.0
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-0.3.3
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-sys-0.3.3
CARGO_CRATE_DEPENDS+=	futures-0.3.4
CARGO_CRATE_DEPENDS+=	futures-channel-0.3.4
CARGO_CRATE_DEPENDS+=	futures-core-0.3.4
CARGO_CRATE_DEPENDS+=	futures-executor-0.3.4
CARGO_CRATE_DEPENDS+=	futures-io-0.3.4
CARGO_CRATE_DEPENDS+=	futures-macro-0.3.4
CARGO_CRATE_DEPENDS+=	futures-sink-0.3.4
CARGO_CRATE_DEPENDS+=	futures-task-0.3.4
CARGO_CRATE_DEPENDS+=	futures-util-0.3.4
CARGO_CRATE_DEPENDS+=	getrandom-0.1.14
CARGO_CRATE_DEPENDS+=	hermit-abi-0.1.8
CARGO_CRATE_DEPENDS+=	hex-0.4.2
CARGO_CRATE_DEPENDS+=	iovec-0.1.4
CARGO_CRATE_DEPENDS+=	jemalloc-sys-0.3.2
CARGO_CRATE_DEPENDS+=	jemallocator-0.3.2
CARGO_CRATE_DEPENDS+=	jemallocator-global-0.3.2
CARGO_CRATE_DEPENDS+=	kernel32-sys-0.2.2
CARGO_CRATE_DEPENDS+=	lazy_static-1.4.0
CARGO_CRATE_DEPENDS+=	libc-0.2.67
CARGO_CRATE_DEPENDS+=	libc-0.2.68
CARGO_CRATE_DEPENDS+=	libc-0.2.69
CARGO_CRATE_DEPENDS+=	log-0.4.8
CARGO_CRATE_DEPENDS+=	maybe-uninit-2.0.0
CARGO_CRATE_DEPENDS+=	memchr-2.3.3
CARGO_CRATE_DEPENDS+=	memmap-0.7.0
CARGO_CRATE_DEPENDS+=	memoffset-0.5.3
CARGO_CRATE_DEPENDS+=	memory-module-sys-0.3.0
CARGO_CRATE_DEPENDS+=	micro-timer-0.3.0
CARGO_CRATE_DEPENDS+=	micro-timer-macros-0.3.0
CARGO_CRATE_DEPENDS+=	mio-0.6.21
CARGO_CRATE_DEPENDS+=	mio-named-pipes-0.1.6
CARGO_CRATE_DEPENDS+=	mio-uds-0.6.7
CARGO_CRATE_DEPENDS+=	miow-0.2.1
CARGO_CRATE_DEPENDS+=	miow-0.3.3
CARGO_CRATE_DEPENDS+=	net2-0.2.33
CARGO_CRATE_DEPENDS+=	num-integer-0.1.42
CARGO_CRATE_DEPENDS+=	num-traits-0.2.11
CARGO_CRATE_DEPENDS+=	num_cpus-1.12.0
CARGO_CRATE_DEPENDS+=	output_vt100-0.1.2
CARGO_CRATE_DEPENDS+=	paste-0.1.9
CARGO_CRATE_DEPENDS+=	paste-impl-0.1.9
CARGO_CRATE_DEPENDS+=	pin-project-lite-0.1.4
CARGO_CRATE_DEPENDS+=	pin-utils-0.1.0-alpha.4
CARGO_CRATE_DEPENDS+=	ppv-lite86-0.2.6
CARGO_CRATE_DEPENDS+=	pretty_assertions-0.6.1
CARGO_CRATE_DEPENDS+=	proc-macro-hack-0.5.15
CARGO_CRATE_DEPENDS+=	proc-macro-nested-0.1.4
CARGO_CRATE_DEPENDS+=	proc-macro2-1.0.10
CARGO_CRATE_DEPENDS+=	proc-macro2-1.0.9
CARGO_CRATE_DEPENDS+=	pyembed-0.7.0
CARGO_CRATE_DEPENDS+=	python-packed-resources-0.1.0
CARGO_CRATE_DEPENDS+=	python27-sys-0.4.1
CARGO_CRATE_DEPENDS+=	python3-sys-0.4.1
CARGO_CRATE_DEPENDS+=	quote-1.0.3
CARGO_CRATE_DEPENDS+=	rand-0.7.3
CARGO_CRATE_DEPENDS+=	rand_chacha-0.2.2
CARGO_CRATE_DEPENDS+=	rand_core-0.5.1
CARGO_CRATE_DEPENDS+=	rand_distr-0.2.2
CARGO_CRATE_DEPENDS+=	rand_hc-0.2.0
CARGO_CRATE_DEPENDS+=	rand_pcg-0.2.1
CARGO_CRATE_DEPENDS+=	rayon-1.3.0
CARGO_CRATE_DEPENDS+=	rayon-core-1.7.0
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.56
CARGO_CRATE_DEPENDS+=	regex-1.3.6
CARGO_CRATE_DEPENDS+=	regex-1.3.9
CARGO_CRATE_DEPENDS+=	regex-syntax-0.6.17
CARGO_CRATE_DEPENDS+=	regex-syntax-0.6.18
CARGO_CRATE_DEPENDS+=	remove_dir_all-0.5.2
CARGO_CRATE_DEPENDS+=	rustc_version-0.2.3
CARGO_CRATE_DEPENDS+=	same-file-1.0.6
CARGO_CRATE_DEPENDS+=	scopeguard-1.1.0
CARGO_CRATE_DEPENDS+=	semver-0.9.0
CARGO_CRATE_DEPENDS+=	semver-parser-0.7.0
CARGO_CRATE_DEPENDS+=	signal-hook-registry-1.2.0
CARGO_CRATE_DEPENDS+=	simple_logger-1.6.0
CARGO_CRATE_DEPENDS+=	slab-0.4.2
CARGO_CRATE_DEPENDS+=	socket2-0.3.12
CARGO_CRATE_DEPENDS+=	strsim-0.8.0
CARGO_CRATE_DEPENDS+=	syn-1.0.16
CARGO_CRATE_DEPENDS+=	syn-1.0.17
CARGO_CRATE_DEPENDS+=	tempfile-3.1.0
CARGO_CRATE_DEPENDS+=	textwrap-0.11.0
CARGO_CRATE_DEPENDS+=	thread_local-1.0.1
CARGO_CRATE_DEPENDS+=	time-0.1.42
CARGO_CRATE_DEPENDS+=	tokio-0.2.18
CARGO_CRATE_DEPENDS+=	tokio-hglib-0.3.0
CARGO_CRATE_DEPENDS+=	tokio-macros-0.2.5
CARGO_CRATE_DEPENDS+=	tokio-util-0.3.1
CARGO_CRATE_DEPENDS+=	twox-hash-1.5.0
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.7
CARGO_CRATE_DEPENDS+=	unicode-xid-0.2.0
CARGO_CRATE_DEPENDS+=	uuid-0.8.1
CARGO_CRATE_DEPENDS+=	vec_map-0.8.1
CARGO_CRATE_DEPENDS+=	wasi-0.9.0+wasi-snapshot-preview1
CARGO_CRATE_DEPENDS+=	winapi-0.2.8
CARGO_CRATE_DEPENDS+=	winapi-0.3.8
CARGO_CRATE_DEPENDS+=	winapi-build-0.1.1
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-util-0.1.3
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	ws2_32-sys-0.2.1

RUST_REQ+=	1.34.2
.include "../../lang/rust/cargo.mk"
.else
TEST_MAKE_FLAGS+=       CARGO=/dev/null
.endif
