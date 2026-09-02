# $NetBSD: Makefile,v 1.46 2026/09/02 19:00:55 wiz Exp $

DISTNAME=	librespot-0.8.0
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=librespot-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/librespot-org/librespot/
COMMENT=	Open Source Spotify client library
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

RUST_REQ=		1.85.0
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

CARGO_NO_DEFAULT_FEATURES=	yes
CARGO_FEATURES+=		native-tls with-libmdns

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/librespot \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
