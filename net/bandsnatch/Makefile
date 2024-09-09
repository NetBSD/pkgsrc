# $NetBSD: Makefile,v 1.8 2024/09/09 19:13:19 pin Exp $

DISTNAME=	bandsnatch-0.3.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ovyerus/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Ovyerus/bandsnatch/
COMMENT=	CLI batch downloader for your Bandcamp collection
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
