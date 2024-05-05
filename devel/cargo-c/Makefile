# $NetBSD: Makefile,v 1.17 2024/05/05 16:08:21 pin Exp $

DISTNAME=	cargo-c-0.9.32
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lu-zero/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/lu-zero/cargo-c
COMMENT=	Build and install C-compatible libraries from Rust lang
LICENSE=	2-clause-bsd

SITES.curl-sys-0.4.72+curl-8.6.0.crate=	https://static.crates.io/crates/curl-sys/

USE_TOOLS+=	pkg-config

RUST_REQ=	1.76.0
#RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgit2}/lib

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

#.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
