# $NetBSD: Makefile,v 1.1 2018/11/04 00:28:01 ryoon Exp $

DISTNAME=	cbindgen-0.6.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=eqrion/}
GITHUB_PROJECT=	cbindgen
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/eqrion/cbindgen/releases
COMMENT=	Generating C bindings from Rust code
LICENSE=	mpl-2.0

CARGO_CRATE_DEPENDS+=	\
	ansi_term-0.11.0 \
	atty-0.2.10 \
	bitflags-1.0.3 \
	cfg-if-0.1.3 \
	clap-2.31.2 \
	cloudabi-0.0.3 \
	dtoa-0.4.2 \
	fuchsia-zircon-0.3.3 \
	fuchsia-zircon-sys-0.3.3 \
	itoa-0.4.1 \
	libc-0.2.41 \
	log-0.4.1 \
	proc-macro2-0.3.8 \
	proc-macro2-0.4.4 \
	quote-0.5.2 \
	quote-0.6.3 \
	rand-0.5.5 \
	rand_core-0.2.1 \
	redox_syscall-0.1.40 \
	redox_termios-0.1.1 \
	remove_dir_all-0.5.1 \
	serde-1.0.64 \
	serde_derive-1.0.58 \
	serde_json-1.0.19 \
	strsim-0.7.0 \
	syn-0.13.11 \
	syn-0.14.1 \
	tempfile-3.0.3 \
	termion-1.5.1 \
	textwrap-0.9.0 \
	toml-0.4.6 \
	unicode-width-0.1.5 \
	unicode-xid-0.1.0 \
	vec_map-0.8.1 \
	winapi-0.3.4 \
	winapi-i686-pc-windows-gnu-0.4.0 \
	winapi-x86_64-pc-windows-gnu-0.4.0

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo build --locked --frozen --release

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cbindgen ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
