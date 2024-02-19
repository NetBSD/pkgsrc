# $NetBSD: Makefile,v 1.8 2024/02/19 08:21:35 pin Exp $

DISTNAME=	inlyne-0.3.3
# 0.4.0 has been release but, do not update to it, see:
# https://github.com/trimental/inlyne/issues/248
# Waiting for 0.4.1 to include the fix.
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=trimental/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/trimental/inlyne/
COMMENT=	GPU powered, browserless, markdown and html viewer
LICENSE=	mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin share/examples/inlyne

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.freetype2}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/inlyne \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/inlyne.toml.sample \
		${DESTDIR}${PREFIX}/share/examples/inlyne

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
