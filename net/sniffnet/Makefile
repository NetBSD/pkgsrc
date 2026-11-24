# $NetBSD: Makefile,v 1.25 2026/11/24 18:33:18 pin Exp $

DISTNAME=	sniffnet-1.6.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=GyulyVGC/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sniffnet.net/
COMMENT=	Application to comfortably monitor your network traffic
LICENSE=	mit OR apache-2.0

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

#RUST_REQ=	1.101.0-beta.3
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.101.0-beta.3 on amd64
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.alsa-lib}/lib

DEPENDS+=	alsa-plugins-oss-[0-9]*:../../audio/alsa-plugins-oss

.include "../../lang/rust/cargo.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
