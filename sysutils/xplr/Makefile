# $NetBSD: Makefile,v 1.62 2025/01/30 10:57:52 pin Exp $

DISTNAME=	xplr-0.21.10
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sayanarijit/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://xplr.dev/
COMMENT=	Hackable, minimal, fast TUI file explorer
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.83.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.83.0 on amd64
USE_TOOLS+=	pkg-config bash:run

INSTALLATION_DIRS=	share/examples/xplr share/applications share/icons/hicolor/scalable/apps

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.LuaJIT2}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.LuaJIT2}/lib

CARGO_NO_DEFAULT_FEATURES=	YES

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/init.lua \
		${DESTDIR}${PREFIX}/share/examples/xplr
	${INSTALL_DATA} ${WRKSRC}/assets/desktop/xplr.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/assets/icon/xplr.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include "../../lang/rust/cargo.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
