# $NetBSD: Makefile,v 1.1 2018/10/23 23:01:33 maya Exp $

DISTNAME=	cbindgen-0.6.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=eqrion/}
GITHUB_PROJECT=	cbindgen
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eqrion/cbindgen
COMMENT=	Generates C bindings from Rust code
LICENSE=	mpl-2.0

CARGO_CRATE_DEPENDS+=	ansi_term-0.11.0
CARGO_CRATE_DEPENDS+=	atty-0.2.10
CARGO_CRATE_DEPENDS+=	bitflags-1.0.3
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.3
CARGO_CRATE_DEPENDS+=	clap-2.31.2
CARGO_CRATE_DEPENDS+=	cloudabi-0.0.3
CARGO_CRATE_DEPENDS+=	dtoa-0.4.2
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-0.3.3
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-sys-0.3.3
CARGO_CRATE_DEPENDS+=	itoa-0.4.1
CARGO_CRATE_DEPENDS+=	libc-0.2.41
CARGO_CRATE_DEPENDS+=	log-0.4.1
CARGO_CRATE_DEPENDS+=	proc-macro2-0.3.8
CARGO_CRATE_DEPENDS+=	proc-macro2-0.4.4
CARGO_CRATE_DEPENDS+=	quote-0.5.2
CARGO_CRATE_DEPENDS+=	quote-0.6.3
CARGO_CRATE_DEPENDS+=	rand-0.5.5
CARGO_CRATE_DEPENDS+=	rand_core-0.2.1
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.40
CARGO_CRATE_DEPENDS+=	redox_termios-0.1.1
CARGO_CRATE_DEPENDS+=	remove_dir_all-0.5.1
CARGO_CRATE_DEPENDS+=	serde-1.0.64
CARGO_CRATE_DEPENDS+=	serde_derive-1.0.58
CARGO_CRATE_DEPENDS+=	serde_json-1.0.19
CARGO_CRATE_DEPENDS+=	strsim-0.7.0
CARGO_CRATE_DEPENDS+=	syn-0.13.11
CARGO_CRATE_DEPENDS+=	syn-0.14.1
CARGO_CRATE_DEPENDS+=	tempfile-3.0.3
CARGO_CRATE_DEPENDS+=	termion-1.5.1
CARGO_CRATE_DEPENDS+=	textwrap-0.9.0
CARGO_CRATE_DEPENDS+=	toml-0.4.6
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.5
CARGO_CRATE_DEPENDS+=	unicode-xid-0.1.0
CARGO_CRATE_DEPENDS+=	vec_map-0.8.1
CARGO_CRATE_DEPENDS+=	winapi-0.3.4
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo build --locked --frozen --release

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cbindgen ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
BUILDLINK_DEPMETHOD.rust+=build
.include "../../lang/rust/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
