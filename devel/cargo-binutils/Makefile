# $NetBSD: Makefile,v 1.2 2025/10/21 08:14:56 wiz Exp $

DISTNAME=	cargo-binutils-0.4.0
CATEGORIES=	devel
EXTRACT_SUFX=	.crate

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/rust-embedded/cargo-binutils/
COMMENT=	Invoke the LLVM tools shipped with the Rust toolchain
LICENSE=	apache-2.0 OR mit

RUST_REQ+=	1.70.0

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
