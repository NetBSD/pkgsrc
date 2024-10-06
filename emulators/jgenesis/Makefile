# $NetBSD: Makefile,v 1.2 2024/10/06 13:19:15 pin Exp $

DISTNAME=	jgenesis-0.8.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=jsgroth/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jsgroth/jgenesis/
COMMENT=	Sega Genesis - Sega CD - SNES - Master System - Game Gear emulator
LICENSE=	mit

DEPENDS+=	zenity-[0-9]*:../../x11/zenity

.include "cargo-depends.mk"

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
GLYPHON_REV=		47f4126f999753e14728c0862b822677f1b039e2
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		glyphon-${GLYPHON_REV}.tar.gz
SITES.glyphon-${GLYPHON_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=grovesNL/}glyphon/archive/${GLYPHON_REV}.tar.gz

#RUST_REQ=	1.80.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.80.1 on amd64
USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

INSTALLATION_DIRS+=	bin

post-extract:
	mv ${WRKDIR}/glyphon-* ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/jgenesis-cli \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/jgenesis-gui \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/m68000-test-runner \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/mos6502-test-runner \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/spc700-test-runner \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wdc65816-test-runner \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/z80-test-runner \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "NetBSD" || ${X11_TYPE} == "modular"
DEPENDS+=	xrandr-[0-9]*:../../x11/xrandr
.endif

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
