# $NetBSD: Makefile,v 1.12 2025/02/06 11:26:29 pin Exp $

DISTNAME=	inlyne-0.5.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Inlyne-Project/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Inlyne-Project/inlyne
COMMENT=	GPU powered, browserless, markdown and html viewer
LICENSE=	mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

RUST_REQ=	1.81.0
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin share/examples/inlyne share/applications

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.freetype2}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/inlyne \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/inlyne.default.toml \
		${DESTDIR}${PREFIX}/share/examples/inlyne
	${INSTALL_DATA} ${WRKSRC}/assets/inlyne.desktop \
		${DESTDIR}${PREFIX}/share/applications

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		x11

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
