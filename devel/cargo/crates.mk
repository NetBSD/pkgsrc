# $NetBSD: crates.mk,v 1.1 2017/09/13 00:12:54 ryoon Exp $
#
# For offline build of crates for devel/cargo
#
# used by devel/cargo/Makefile

CRATES+=	advapi32-sys-0.2.0
CRATES+=	aho-corasick-0.5.3
CRATES+=	aho-corasick-0.6.3
CRATES+=	bitflags-0.7.0
CRATES+=	bufstream-0.1.2
CRATES+=	cfg-if-0.1.0
CRATES+=	chrono-0.2.25
CRATES+=	cmake-0.1.19
CRATES+=	crossbeam-0.2.10
CRATES+=	curl-0.4.1
CRATES+=	curl-sys-0.3.6
CRATES+=	docopt-0.6.86
CRATES+=	dtoa-0.4.1
CRATES+=	env_logger-0.3.5
CRATES+=	filetime-0.1.10
CRATES+=	flate2-0.2.14
CRATES+=	foreign-types-0.2.0
CRATES+=	fs2-0.3.0
CRATES+=	gcc-0.3.39
CRATES+=	gdi32-sys-0.2.0
CRATES+=	git2-0.6.3
CRATES+=	git2-curl-0.7.0
CRATES+=	glob-0.2.11
CRATES+=	hamcrest-0.1.1
CRATES+=	idna-0.1.0
CRATES+=	itoa-0.3.1
CRATES+=	kernel32-sys-0.2.2
CRATES+=	lazy_static-0.2.2
CRATES+=	libc-0.2.18
CRATES+=	libgit2-sys-0.6.6
CRATES+=	libssh2-sys-0.2.5
CRATES+=	libz-sys-1.0.13
CRATES+=	log-0.3.6
CRATES+=	matches-0.1.4
CRATES+=	memchr-0.1.11
CRATES+=	memchr-1.0.1
CRATES+=	miniz-sys-0.1.7
CRATES+=	miow-0.1.3
CRATES+=	net2-0.2.26
CRATES+=	num-0.1.36
CRATES+=	num-bigint-0.1.35
CRATES+=	num-iter-0.1.32
CRATES+=	num-complex-0.1.35
CRATES+=	num-integer-0.1.32
CRATES+=	num-rational-0.1.35
CRATES+=	num-traits-0.1.36
CRATES+=	num_cpus-1.1.0
CRATES+=	openssl-0.9.6
CRATES+=	openssl-probe-0.1.0
CRATES+=	openssl-sys-0.9.6
CRATES+=	pkg-config-0.3.8
CRATES+=	psapi-sys-0.1.0
CRATES+=	quote-0.3.15
CRATES+=	rand-0.3.14
CRATES+=	redox_syscall-0.1.17
CRATES+=	regex-0.1.80
CRATES+=	regex-0.2.1
CRATES+=	regex-syntax-0.3.9
CRATES+=	regex-syntax-0.4.0
CRATES+=	rustc-serialize-0.3.21
CRATES+=	semver-0.5.1
CRATES+=	semver-parser-0.6.1
CRATES+=	serde-0.9.12
CRATES+=	serde_codegen_internals-0.14.2
CRATES+=	serde_derive-0.9.12
CRATES+=	serde_ignored-0.0.2
CRATES+=	serde_json-0.9.9
CRATES+=	shell-escape-0.1.3
CRATES+=	strsim-0.5.1
CRATES+=	syn-0.11.9
CRATES+=	synom-0.11.3
CRATES+=	tar-0.4.9
CRATES+=	tempdir-0.3.5
CRATES+=	term-0.4.4
CRATES+=	thread-id-2.0.0
CRATES+=	thread-id-3.0.0
CRATES+=	thread_local-0.2.7
CRATES+=	thread_local-0.3.3
CRATES+=	time-0.1.36
CRATES+=	toml-0.2.1
CRATES+=	unicode-bidi-0.2.3
CRATES+=	unicode-normalization-0.1.2
CRATES+=	unicode-xid-0.0.4
CRATES+=	unreachable-0.1.1
CRATES+=	url-1.2.3
CRATES+=	user32-sys-0.2.0
CRATES+=	utf8-ranges-0.1.3
CRATES+=	utf8-ranges-1.0.0
CRATES+=	void-1.0.2
CRATES+=	winapi-0.2.8
CRATES+=	winapi-build-0.1.1
CRATES+=	ws2_32-sys-0.2.1
CRATES+=	metadeps-1.1.1
CRATES+=	error-chain-0.7.2

.for f in ${CRATES}
SITES.${f}.tar.gz=	-https://crates.io/api/v1/crates/${f:C/-[^-]*$//}/${f:C/^.*-//}/download
CARGO_DISTFILES+=	${f}.tar.gz
.endfor

post-extract:
	${MV} ${WRKDIR}/rustc-${RUST_VER}-src/src/rust-installer \
		${WRKSRC}/src
	${MKDIR} ${WRKSRC}/vendor-sources
.for f in ${CRATES}
	${MV} ${WRKDIR}/${f} \
		${WRKSRC}/vendor-sources
.endfor
# Create .cargo/config file
	${MKDIR} ${WRKSRC}/.cargo
	echo "[source.crates-io]" > ${WRKSRC}/.cargo/config
	echo "registry = 'https://github.com/rust-lang/crates.io-index'" >> ${WRKSRC}/.cargo/config
	echo "replace-with = 'vendored-sources'" >> ${WRKSRC}/.cargo/config
	echo >> ${WRKSRC}/.cargo/config
	echo "[source.vendored-sources]" >> ${WRKSRC}/.cargo/config
	echo "directory = '${WRKSRC}/vendor-sources'" >> ${WRKSRC}/.cargo/config

# Use OpenBSD Ports' script to update meta data for crates
.for f in ${CRATES}
	${PERL5} ${FILESDIR}/cargo-generate-vendor.pl \
		${DISTDIR}/${DIST_SUBDIR}/${f}.tar.gz \
		${WRKSRC}/vendor-sources/${f}
.endfor
