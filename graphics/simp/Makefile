# $NetBSD: Makefile,v 1.1 2022/09/17 15:54:23 pin Exp $

DISTNAME=	simp-3.1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Kl4rry/}
GITHUB_TAG=	ae385db9995b20f5801ac8dade10d8756513c11d

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Kl4rry/simp/
COMMENT=	Fast and simple GPU-accelerated image manipulation program
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk3}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libxcb}/lib

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux"
CARGO_NO_DEFAULT_FEATURES=	YES
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/simp \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
