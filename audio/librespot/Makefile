# $NetBSD: Makefile,v 1.35 2024/12/12 07:26:30 pin Exp $

DISTNAME=	librespot-0.6.0
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=librespot-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/librespot-org/librespot/
COMMENT=	Open Source Spotify client library
LICENSE=	mit

TOOL_DEPENDS+=  cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

.include "cargo-depends.mk"

RUST_REQ=		1.75.0
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

CARGO_NO_DEFAULT_FEATURES=	yes

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/librespot \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
