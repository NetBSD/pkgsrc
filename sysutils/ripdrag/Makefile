# $NetBSD: Makefile,v 1.22 2024/10/20 14:04:35 wiz Exp $

DISTNAME=	ripdrag-0.4.10
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://static.crates.io/crates/ripdrag/
EXTRACT_SUFX=	.crate


MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/nik012003/ripdrag/
COMMENT=	Drag and Drop utilty written in Rust and GTK4
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

RUST_REQ=		1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64
USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk4}/lib

.include "../../lang/rust/cargo.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.at-spi2-core+=	at-spi2-core>=2.54
.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
