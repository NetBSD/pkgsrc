# $NetBSD: Makefile,v 1.3 2023/09/26 07:09:52 pin Exp $

# Do not update. Newer version require Rust > 1.70
DISTNAME=	four-bar-rs-4.0.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=KmolYuan/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KmolYuan/four-bar-rs/
COMMENT=	Simulator and synthesizing tool for four-bar linkage mechanism
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk3}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/four-bar \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
