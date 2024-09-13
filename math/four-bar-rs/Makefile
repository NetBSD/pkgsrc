# $NetBSD: Makefile,v 1.19 2024/09/13 18:04:02 pin Exp $

DISTNAME=	four-bar-rs-7.0.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=KmolYuan/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/KmolYuan/four-bar-rs/
COMMENT=	Simulator and synthesizing tool for four-bar linkage mechanism
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	git-base-[0-9]*:../../devel/git-base

.include "cargo-depends.mk"

#RUST_REQ=	1.80.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.80.1 on amd64
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
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
