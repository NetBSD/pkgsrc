# $NetBSD: Makefile,v 1.55 2024/12/02 07:20:20 pin Exp $

DISTNAME=	spotify-player-0.20.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=aome510/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/aome510/spotify-player/
COMMENT=	Command driven spotify player
LICENSE=	mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

.include "cargo-depends.mk"

#RUST_REQ=	1.82.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.82.0 on amd64

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

CARGO_NO_DEFAULT_FEATURES=	YES

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/spotify_player \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
