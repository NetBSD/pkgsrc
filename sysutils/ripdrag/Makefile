# $NetBSD: Makefile,v 1.19 2024/04/28 16:33:23 pin Exp $

DISTNAME=	ripdrag-0.4.8
CATEGORIES=	sysutils
MASTER_SITES=	https://static.crates.io/crates/ripdrag/
EXTRACT_SUFX=	.crate


MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/nik012003/ripdrag/
COMMENT=	Drag and Drop utilty written in Rust and GTK4
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk4}/lib

.include "../../lang/rust/cargo.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
