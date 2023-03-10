# $NetBSD: Makefile,v 1.1 2023/03/10 21:27:09 ryoon Exp $

DISTNAME=	cargo-c-0.9.15+cargo-0.67
PKGNAME=	${DISTNAME:C/\\+cargo-[[:digit:]\.]*//}
CATEGORIES=	devel
MAINTAINER=	ryoon@NetBSD.org
MASTER_SITES=	https://static.crates.io/crates/cargo-c/
HOMEPAGE=	https://github.com/lu-zero/cargo-c
COMMENT=	Build and install C-compatible libraries from Rust lang
LICENSE=	2-clause-bsd
EXTRACT_SUFX=	.crate

SITES.curl-sys-0.4.59+curl-7.86.0.crate=	https://static.crates.io/crates/curl-sys/

USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgit2}/lib

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

CARGOC_PROGRAMS+=	cargo-capi
CARGOC_PROGRAMS+=	cargo-cbuild
CARGOC_PROGRAMS+=	cargo-cinstall
CARGOC_PROGRAMS+=	cargo-ctest

do-install:
.for f in ${CARGOC_PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/${f} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
