# $NetBSD: Makefile,v 1.3 2024/02/29 14:23:09 pin Exp $

DISTNAME=	rust-bindgen-0.69.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rust-lang/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_PROJECT=	rust-bindgen
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/rust-lang/rust-bindgen/
COMMENT=	Automatically generate Rust FFI bindings to C (and some C++) libraries
LICENSE=	modified-bsd

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/bindgen ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
