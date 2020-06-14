# $NetBSD: Makefile,v 1.2 2020/06/14 15:33:28 nia Exp $

DISTNAME=	tealdeer-1.3.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dbrgn/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/dbrgn/tealdeer/
COMMENT=	Simplified, example based and community-driven man pages
LICENSE=	mit OR apache-2.0

USE_LANGUAGES=	c # rust

CARGO_CRATE_DEPENDS+=	adler32-1.0.4
CARGO_CRATE_DEPENDS+=	aho-corasick-0.7.9
CARGO_CRATE_DEPENDS+=	ansi_term-0.12.1
CARGO_CRATE_DEPENDS+=	anyhow-1.0.26
CARGO_CRATE_DEPENDS+=	app_dirs-1.2.1
CARGO_CRATE_DEPENDS+=	assert_cmd-0.10.2
CARGO_CRATE_DEPENDS+=	atty-0.2.14
CARGO_CRATE_DEPENDS+=	autocfg-1.0.0
CARGO_CRATE_DEPENDS+=	base64-0.11.0
CARGO_CRATE_DEPENDS+=	bitflags-1.2.1
CARGO_CRATE_DEPENDS+=	bumpalo-3.2.0
CARGO_CRATE_DEPENDS+=	bytes-0.5.4
CARGO_CRATE_DEPENDS+=	c2-chacha-0.2.3
CARGO_CRATE_DEPENDS+=	cc-1.0.50
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.10
CARGO_CRATE_DEPENDS+=	core-foundation-0.6.4
CARGO_CRATE_DEPENDS+=	core-foundation-sys-0.6.2
CARGO_CRATE_DEPENDS+=	crc32fast-1.2.0
CARGO_CRATE_DEPENDS+=	difference-2.0.0
CARGO_CRATE_DEPENDS+=	docopt-1.1.0
CARGO_CRATE_DEPENDS+=	dtoa-0.4.5
CARGO_CRATE_DEPENDS+=	encoding_rs-0.8.22
CARGO_CRATE_DEPENDS+=	env_logger-0.7.1
CARGO_CRATE_DEPENDS+=	errno-0.2.4
CARGO_CRATE_DEPENDS+=	errno-dragonfly-0.1.1
CARGO_CRATE_DEPENDS+=	escargot-0.3.1
CARGO_CRATE_DEPENDS+=	filetime-0.2.8
CARGO_CRATE_DEPENDS+=	flate2-1.0.13
CARGO_CRATE_DEPENDS+=	float-cmp-0.6.0
CARGO_CRATE_DEPENDS+=	fnv-1.0.6
CARGO_CRATE_DEPENDS+=	foreign-types-0.3.2
CARGO_CRATE_DEPENDS+=	foreign-types-shared-0.1.1
CARGO_CRATE_DEPENDS+=	fuchsia-cprng-0.1.1
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-0.3.3
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-sys-0.3.3
CARGO_CRATE_DEPENDS+=	futures-channel-0.3.4
CARGO_CRATE_DEPENDS+=	futures-core-0.3.4
CARGO_CRATE_DEPENDS+=	futures-io-0.3.4
CARGO_CRATE_DEPENDS+=	futures-sink-0.3.4
CARGO_CRATE_DEPENDS+=	futures-task-0.3.4
CARGO_CRATE_DEPENDS+=	futures-util-0.3.4
CARGO_CRATE_DEPENDS+=	gcc-0.3.55
CARGO_CRATE_DEPENDS+=	getrandom-0.1.14
CARGO_CRATE_DEPENDS+=	h2-0.2.1
CARGO_CRATE_DEPENDS+=	heck-0.3.1
CARGO_CRATE_DEPENDS+=	hermit-abi-0.1.8
CARGO_CRATE_DEPENDS+=	http-0.2.0
CARGO_CRATE_DEPENDS+=	http-body-0.3.1
CARGO_CRATE_DEPENDS+=	httparse-1.3.4
CARGO_CRATE_DEPENDS+=	humantime-1.3.0
CARGO_CRATE_DEPENDS+=	hyper-0.13.2
CARGO_CRATE_DEPENDS+=	hyper-tls-0.4.1
CARGO_CRATE_DEPENDS+=	idna-0.2.0
CARGO_CRATE_DEPENDS+=	indexmap-1.3.2
CARGO_CRATE_DEPENDS+=	iovec-0.1.4
CARGO_CRATE_DEPENDS+=	itoa-0.4.5
CARGO_CRATE_DEPENDS+=	js-sys-0.3.35
CARGO_CRATE_DEPENDS+=	kernel32-sys-0.2.2
CARGO_CRATE_DEPENDS+=	lazy_static-1.4.0
CARGO_CRATE_DEPENDS+=	libc-0.2.67
CARGO_CRATE_DEPENDS+=	log-0.4.8
CARGO_CRATE_DEPENDS+=	matches-0.1.8
CARGO_CRATE_DEPENDS+=	memchr-2.3.3
CARGO_CRATE_DEPENDS+=	mime-0.3.16
CARGO_CRATE_DEPENDS+=	mime_guess-2.0.1
CARGO_CRATE_DEPENDS+=	miniz_oxide-0.3.6
CARGO_CRATE_DEPENDS+=	mio-0.6.21
CARGO_CRATE_DEPENDS+=	miow-0.2.1
CARGO_CRATE_DEPENDS+=	native-tls-0.2.3
CARGO_CRATE_DEPENDS+=	net2-0.2.33
CARGO_CRATE_DEPENDS+=	nom-4.2.3
CARGO_CRATE_DEPENDS+=	normalize-line-endings-0.2.2
CARGO_CRATE_DEPENDS+=	num-traits-0.2.11
CARGO_CRATE_DEPENDS+=	num_cpus-1.12.0
CARGO_CRATE_DEPENDS+=	ole32-sys-0.2.0
CARGO_CRATE_DEPENDS+=	openssl-0.10.28
CARGO_CRATE_DEPENDS+=	openssl-probe-0.1.2
CARGO_CRATE_DEPENDS+=	openssl-sys-0.9.54
CARGO_CRATE_DEPENDS+=	pager-0.15.0
CARGO_CRATE_DEPENDS+=	percent-encoding-2.1.0
CARGO_CRATE_DEPENDS+=	pin-project-0.4.8
CARGO_CRATE_DEPENDS+=	pin-project-internal-0.4.8
CARGO_CRATE_DEPENDS+=	pin-project-lite-0.1.4
CARGO_CRATE_DEPENDS+=	pin-utils-0.1.0-alpha.4
CARGO_CRATE_DEPENDS+=	pkg-config-0.3.17
CARGO_CRATE_DEPENDS+=	ppv-lite86-0.2.6
CARGO_CRATE_DEPENDS+=	predicates-1.0.3
CARGO_CRATE_DEPENDS+=	predicates-core-1.0.0
CARGO_CRATE_DEPENDS+=	predicates-tree-1.0.0
CARGO_CRATE_DEPENDS+=	proc-macro2-1.0.9
CARGO_CRATE_DEPENDS+=	quick-error-1.2.3
CARGO_CRATE_DEPENDS+=	quote-1.0.2
CARGO_CRATE_DEPENDS+=	rand-0.4.6
CARGO_CRATE_DEPENDS+=	rand-0.7.3
CARGO_CRATE_DEPENDS+=	rand_chacha-0.2.1
CARGO_CRATE_DEPENDS+=	rand_core-0.3.1
CARGO_CRATE_DEPENDS+=	rand_core-0.4.2
CARGO_CRATE_DEPENDS+=	rand_core-0.5.1
CARGO_CRATE_DEPENDS+=	rand_hc-0.2.0
CARGO_CRATE_DEPENDS+=	rdrand-0.4.0
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.56
CARGO_CRATE_DEPENDS+=	regex-1.3.4
CARGO_CRATE_DEPENDS+=	regex-syntax-0.6.14
CARGO_CRATE_DEPENDS+=	remove_dir_all-0.5.2
CARGO_CRATE_DEPENDS+=	reqwest-0.10.3
CARGO_CRATE_DEPENDS+=	ryu-1.0.2
CARGO_CRATE_DEPENDS+=	same-file-1.0.6
CARGO_CRATE_DEPENDS+=	schannel-0.1.17
CARGO_CRATE_DEPENDS+=	security-framework-0.3.4
CARGO_CRATE_DEPENDS+=	security-framework-sys-0.3.3
CARGO_CRATE_DEPENDS+=	serde-1.0.104
CARGO_CRATE_DEPENDS+=	serde_derive-1.0.104
CARGO_CRATE_DEPENDS+=	serde_json-1.0.48
CARGO_CRATE_DEPENDS+=	serde_urlencoded-0.6.1
CARGO_CRATE_DEPENDS+=	shell32-sys-0.1.2
CARGO_CRATE_DEPENDS+=	slab-0.4.2
CARGO_CRATE_DEPENDS+=	smallvec-1.2.0
CARGO_CRATE_DEPENDS+=	sourcefile-0.1.4
CARGO_CRATE_DEPENDS+=	strsim-0.9.3
CARGO_CRATE_DEPENDS+=	syn-1.0.16
CARGO_CRATE_DEPENDS+=	tar-0.4.26
CARGO_CRATE_DEPENDS+=	tempdir-0.3.7
CARGO_CRATE_DEPENDS+=	tempfile-3.1.0
CARGO_CRATE_DEPENDS+=	termcolor-1.1.0
CARGO_CRATE_DEPENDS+=	thread_local-1.0.1
CARGO_CRATE_DEPENDS+=	time-0.1.42
CARGO_CRATE_DEPENDS+=	tokio-0.2.12
CARGO_CRATE_DEPENDS+=	tokio-tls-0.3.0
CARGO_CRATE_DEPENDS+=	tokio-util-0.2.0
CARGO_CRATE_DEPENDS+=	toml-0.5.6
CARGO_CRATE_DEPENDS+=	tower-service-0.3.0
CARGO_CRATE_DEPENDS+=	treeline-0.1.0
CARGO_CRATE_DEPENDS+=	try-lock-0.2.2
CARGO_CRATE_DEPENDS+=	unicase-2.6.0
CARGO_CRATE_DEPENDS+=	unicode-bidi-0.3.4
CARGO_CRATE_DEPENDS+=	unicode-normalization-0.1.12
CARGO_CRATE_DEPENDS+=	unicode-segmentation-1.6.0
CARGO_CRATE_DEPENDS+=	unicode-xid-0.2.0
CARGO_CRATE_DEPENDS+=	url-2.1.1
CARGO_CRATE_DEPENDS+=	utime-0.2.1
CARGO_CRATE_DEPENDS+=	vcpkg-0.2.8
CARGO_CRATE_DEPENDS+=	version_check-0.1.5
CARGO_CRATE_DEPENDS+=	version_check-0.9.1
CARGO_CRATE_DEPENDS+=	walkdir-2.3.1
CARGO_CRATE_DEPENDS+=	want-0.3.0
CARGO_CRATE_DEPENDS+=	wasi-0.9.0+wasi-snapshot-preview1
CARGO_CRATE_DEPENDS+=	wasm-bindgen-0.2.58
CARGO_CRATE_DEPENDS+=	wasm-bindgen-backend-0.2.58
CARGO_CRATE_DEPENDS+=	wasm-bindgen-futures-0.4.8
CARGO_CRATE_DEPENDS+=	wasm-bindgen-macro-0.2.58
CARGO_CRATE_DEPENDS+=	wasm-bindgen-macro-support-0.2.58
CARGO_CRATE_DEPENDS+=	wasm-bindgen-shared-0.2.58
CARGO_CRATE_DEPENDS+=	wasm-bindgen-webidl-0.2.58
CARGO_CRATE_DEPENDS+=	web-sys-0.3.35
CARGO_CRATE_DEPENDS+=	weedle-0.10.0
CARGO_CRATE_DEPENDS+=	winapi-0.2.8
CARGO_CRATE_DEPENDS+=	winapi-0.3.8
CARGO_CRATE_DEPENDS+=	winapi-build-0.1.1
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-util-0.1.3
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winreg-0.6.2
CARGO_CRATE_DEPENDS+=	ws2_32-sys-0.2.1
CARGO_CRATE_DEPENDS+=	xattr-0.2.2
CARGO_CRATE_DEPENDS+=	xdg-2.2.0

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}

INSTALLATION_DIRS=	bin share/bash-completion/completions

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo build --locked --frozen --release -j${_MAKE_JOBS_N}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tldr ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/bash_tealdeer ${DESTDIR}${PREFIX}/share/bash-completion/completions/tldr

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
