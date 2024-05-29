# $NetBSD: Makefile,v 1.57 2024/05/29 16:35:18 adam Exp $

DISTNAME=	termusic-0.9.0
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=tramhao/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tramhao/termusic/
COMMENT=	Music Player TUI written in Rust
LICENSE=	mit AND gnu-gpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gstreamer1}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		gst

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/termusic \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/termusic-server \
		${DESTDIR}${PREFIX}/bin

DEPENDS+=	gst-plugins1-libav-[0-9]*:../../multimedia/gst-plugins1-libav
DEPENDS+=	gstreamer1-default-backend-[0-9]*:../../meta-pkgs/gstreamer1-default-backend
DEPENDS+=	yt-dlp-[0-9]*:../../net/yt-dlp
DEPENDS+=	alsa-plugins-oss-[0-9]*:../../audio/alsa-plugins-oss

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../multimedia/gst-plugins1-ugly/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
