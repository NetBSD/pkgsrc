# $NetBSD: Makefile,v 1.26 2022/12/21 22:17:08 pin Exp $

# Don't update, newer versions require Rust >= 1.65 to build.
# If you have at least Rust-1.65, you can find 0.73.0 in wip.
DISTNAME=	nushell-0.71.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=nushell/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://www.nushell.sh/
COMMENT=	New type of shell
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin
PKG_SHELL=		bin/nu

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

# The 'trash-support' feature is default but, does not build on NetBSD.
# Extra features 'dataframe' and 'database' do build on NetBSD.
# Uncomment them if you wish to enable these at build time.
# Be aware that doing so will increase the package build time.

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux"
CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		plugin which-support #dataframe database
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/nu \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
