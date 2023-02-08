# $NetBSD: Makefile,v 1.4 2023/02/08 08:41:22 pin Exp $

DISTNAME=	sniffnet-1.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=GyulyVGC/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GyulyVGC/sniffnet/
COMMENT=	Application to comfortably monitor your network traffic
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.alsa-lib}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sniffnet \
		${DESTDIR}${PREFIX}/bin

DEPENDS+=	alsa-plugins-oss-[0-9]*:../../audio/alsa-plugins-oss

.include "../../lang/rust/cargo.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
