# $NetBSD: Makefile,v 1.19 2024/05/16 06:15:14 wiz Exp $

DISTNAME=	t-rec-rs-0.7.6
PKGNAME=	t-rec-0.7.6
PKGREVISION=	13
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=sassman/}
GITHUB_PROJECT=	t-rec-rs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sassman/t-rec-rs/
COMMENT=	Terminal recorder
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	glib2-[0-9]*:../../devel/glib2

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

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
