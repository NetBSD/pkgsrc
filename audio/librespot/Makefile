# $NetBSD: Makefile,v 1.6 2021/02/07 06:30:13 ryoon Exp $

DISTNAME=	librespot-0.1.3
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=librespot-org/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
#Track a specific commit until upstream provides a new release
GITHUB_PROJECT=	librespot
GITHUB_TAG=	a2f832dff171914935f7e1a98a5da3d7c8a0b789

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/librespot-org/librespot/
COMMENT=	Open Source Spotify client library
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c # rust, but needs a toolchain to link
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

MAKE_ENV+=	RUSTFLAGS=${RUSTFLAGS:Q}

CARGO_NO_DEFAULT_FEATURES=	yes

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/librespot ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
