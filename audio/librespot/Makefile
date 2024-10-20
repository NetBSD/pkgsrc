# $NetBSD: Makefile,v 1.30 2024/10/20 13:20:55 pin Exp $

DISTNAME=	librespot-0.5.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=librespot-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/librespot-org/librespot/
COMMENT=	Open Source Spotify client library
LICENSE=	mit

TOOL_DEPENDS+=  cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

RUST_REQ=		1.74.0
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=     -C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.clang}/lib

CARGO_NO_DEFAULT_FEATURES=	yes

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/librespot \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
