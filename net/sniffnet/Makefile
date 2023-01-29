# $NetBSD: Makefile,v 1.3 2023/01/29 21:17:30 ryoon Exp $

DISTNAME=	sniffnet-1.0.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=GyulyVGC/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	69aefda2c57764e2b4077bf07e5fefdf6c5c71a7

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/GyulyVGC/sniffnet/
COMMENT=	Application to comfortably monitor your network traffic
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sniffnet \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
