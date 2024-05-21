# $NetBSD: Makefile,v 1.82 2024/05/21 09:20:32 pin Exp $

DISTNAME=	oculante-0.8.22
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=woelper/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/woelper/oculante/
COMMENT=	Minimalistic crossplatform image viewer written in rust
LICENSE=	mit

SITES.spirv-0.3.0+sdk-1.3.268.0.crate=	https://static.crates.io/crates/spirv/

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk3}/lib

# This is needed as pkgsrc defaults to graphics/jpeg.
# If you have graphics/libjpeg-turbo as a local default, it's most probably
# possible to build the package with the turbo feature on.
# The file_open feature has also been switched-off.
# Disabling it will enable a custom file dialog. Upstream has highlighted
# this will probably be the default in the future.
CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		avif_native notan/glsl-to-spirv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/oculante \
		${DESTDIR}${PREFIX}/bin

DEPENDS+=	nasm-[0-9]*:../../devel/nasm

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
