# $NetBSD: Makefile,v 1.1 2023/05/09 21:28:06 nikita Exp $

DISTNAME=	cargo-binutils-0.3.6
CATEGORIES=	devel
MAINTAINER=	nikita@NetBSD.org
# the version on github has no Cargo.lock
MASTER_SITES=	https://static.crates.io/crates/cargo-binutils/
EXTRACT_SUFX=	.crate

HOMEPAGE=	https://github.com/rust-embedded/cargo-binutils/
COMMENT=	Invoke the LLVM tools shipped with the Rust toolchain
LICENSE=	apache-2.0 OR mit

# Minimum Supported Rust Version (MSRV)
# guaranteed to compile on stable Rust 1.60.0 and up.

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

CARGO_BINS+=	cov
CARGO_BINS+=	nm
CARGO_BINS+=	objcopy
CARGO_BINS+=	objdump
CARGO_BINS+=	profdata
CARGO_BINS+=	readobj
CARGO_BINS+=	size
CARGO_BINS+=	strip
RUST_BINS+=	ld
RUST_BINS+=	lld

do-install:
.for f in ${CARGO_BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-${f} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rust-${f} ${DESTDIR}${PREFIX}/bin
.endfor
.for f in ${RUST_BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rust-${f} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
