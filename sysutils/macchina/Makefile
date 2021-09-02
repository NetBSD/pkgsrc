# $NetBSD: Makefile,v 1.29 2021/09/02 08:32:14 pin Exp $

DISTNAME=	macchina-0.9.2
# Newer versions require Rust-1.54
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Macchina-CLI/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Macchina-CLI/macchina/
COMMENT=	Basic system information fetcher
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin share/examples/macchina

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libXdmcp}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libXau}/lib

BUILDLINK_TRANSFORM+=	opt:-pie:-fPIC

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/macchina ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/macchina.toml ${DESTDIR}${PREFIX}/share/examples/macchina

DEPENDS+=	wmctrl-[0-9]*:../../wm/wmctrl

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
