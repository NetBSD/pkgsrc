# $NetBSD: Makefile,v 1.10 2019/12/03 15:50:09 minskim Exp $

DISTNAME=	cbindgen-0.10.1
CATEGORIES=	devel
EXTRACT_SUFX=	.crate

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/eqrion/cbindgen/releases
COMMENT=	Generating C bindings from Rust code
LICENSE=	mpl-2.0

CARGO_CRATE_DEPENDS+=	ansi_term-0.11.0
CARGO_CRATE_DEPENDS+=	atty-0.2.11
CARGO_CRATE_DEPENDS+=	autocfg-0.1.4
CARGO_CRATE_DEPENDS+=	bitflags-1.1.0
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.9
CARGO_CRATE_DEPENDS+=	clap-2.33.0
CARGO_CRATE_DEPENDS+=	cloudabi-0.0.3
CARGO_CRATE_DEPENDS+=	fuchsia-cprng-0.1.1
CARGO_CRATE_DEPENDS+=	itoa-0.4.4
CARGO_CRATE_DEPENDS+=	libc-0.2.58
CARGO_CRATE_DEPENDS+=	log-0.4.6
CARGO_CRATE_DEPENDS+=	numtoa-0.1.0
CARGO_CRATE_DEPENDS+=	proc-macro2-1.0.0
CARGO_CRATE_DEPENDS+=	quote-1.0.0
CARGO_CRATE_DEPENDS+=	rand-0.6.5
CARGO_CRATE_DEPENDS+=	rand_chacha-0.1.1
CARGO_CRATE_DEPENDS+=	rand_core-0.3.1
CARGO_CRATE_DEPENDS+=	rand_core-0.4.0
CARGO_CRATE_DEPENDS+=	rand_hc-0.1.0
CARGO_CRATE_DEPENDS+=	rand_isaac-0.1.1
CARGO_CRATE_DEPENDS+=	rand_jitter-0.1.4
CARGO_CRATE_DEPENDS+=	rand_os-0.1.3
CARGO_CRATE_DEPENDS+=	rand_pcg-0.1.2
CARGO_CRATE_DEPENDS+=	rand_xorshift-0.1.1
CARGO_CRATE_DEPENDS+=	rdrand-0.4.0
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.54
CARGO_CRATE_DEPENDS+=	redox_termios-0.1.1
CARGO_CRATE_DEPENDS+=	remove_dir_all-0.5.2
CARGO_CRATE_DEPENDS+=	ryu-0.2.8
CARGO_CRATE_DEPENDS+=	serde-1.0.93
CARGO_CRATE_DEPENDS+=	serde_derive-1.0.99
CARGO_CRATE_DEPENDS+=	serde_json-1.0.39
CARGO_CRATE_DEPENDS+=	strsim-0.8.0
CARGO_CRATE_DEPENDS+=	syn-1.0.1
CARGO_CRATE_DEPENDS+=	tempfile-3.0.8
CARGO_CRATE_DEPENDS+=	termion-1.5.3
CARGO_CRATE_DEPENDS+=	textwrap-0.11.0
CARGO_CRATE_DEPENDS+=	toml-0.5.1
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.5
CARGO_CRATE_DEPENDS+=	unicode-xid-0.2.0
CARGO_CRATE_DEPENDS+=	vec_map-0.8.1
CARGO_CRATE_DEPENDS+=	winapi-0.3.7
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo build --locked --frozen --release

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cbindgen ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
