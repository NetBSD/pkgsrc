# $NetBSD: Makefile,v 1.37 2025/09/21 15:11:42 wiz Exp $

DISTNAME=	t-rec-rs-0.7.9
PKGNAME=	t-rec-0.7.9
PKGREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=sassman/}
GITHUB_PROJECT=	t-rec-rs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sassman/t-rec-rs/
COMMENT=	Terminal recorder
LICENSE=	gnu-gpl-v3

SITES.wasi-0.13.3+wasi-0.2.2.crate=		https://static.crates.io/crates/wasi/

TOOL_DEPENDS+=	glib2-[0-9]*:../../devel/glib2

.include "cargo-depends.mk"

#RUST_REQ=	1.85.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.85.0 on amd64
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/t-rec \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
