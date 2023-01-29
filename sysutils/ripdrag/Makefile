# $NetBSD: Makefile,v 1.4 2023/01/29 21:17:50 ryoon Exp $

DISTNAME=	ripdrag-0.2.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=nik012003/}
GITHUB_TAG=	398857cf87a325ebfaa0faf613a597e6b1f0cfbd

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/nik012003/ripdrag/
COMMENT=	Drag and Drop utilty written in Rust and GTK4
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk4}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ripdrag \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
