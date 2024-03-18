# $NetBSD: Makefile,v 1.59 2024/03/18 13:29:05 pin Exp $

DISTNAME=	xplr-0.21.7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sayanarijit/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://xplr.dev/
COMMENT=	Hackable, minimal, fast TUI file explorer
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config bash:run

INSTALLATION_DIRS=	share/examples/xplr share/applications share/icons/hicolor/scalable/apps

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.LuaJIT2}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.LuaJIT2}/lib

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
