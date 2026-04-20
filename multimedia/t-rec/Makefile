# $NetBSD: Makefile,v 1.45 2026/04/20 18:14:10 adam Exp $

DISTNAME=	t-rec-rs-0.8.2
PKGNAME=	t-rec-0.8.2
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=sassman/}
GITHUB_PROJECT=	t-rec-rs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sassman/t-rec-rs/
COMMENT=	Terminal recorder
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	glib2-[0-9]*:../../devel/glib2

.include "cargo-depends.mk"

#RUST_REQ=	1.92.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.92.0 on amd64

# This package has an optional dependency on ffmpeg8.
# If you would like to save recordings as mp4 files instead of gif,
# please make sure you have ffmpeg8 installed.
SUBST_CLASSES+=		ffmpeg
SUBST_FILES.ffmpeg+=	src/generators/mp4.rs
SUBST_SED.ffmpeg+=	-e 's,"ffmpeg","ffmpeg8",'
SUBST_STAGE.ffmpeg=	pre-build
SUBST_MESSAGE.ffmpeg=	Fixing path to ffmpeg binary.

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/t-rec \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
