# $NetBSD: Makefile,v 1.1 2026/10/18 13:05:41 pin Exp $

DISTNAME=	weatherman-0.5.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=sorinirimies/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sorinirimies/weatherman/
COMMENT=	Desktop and TUI weather app
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

#RUST_REQ=	1.100.0beta.5
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.100.0beta.5 on amd64
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.fontconfig}/lib
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/weatherman \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/weatherman-tui \
		${DESTDIR}${PREFIX}/bin

DEPENDS+=	noto-emoji-ttf-[0-9]*:../../fonts/noto-emoji-ttf

.include "../../lang/rust/cargo.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
