# $NetBSD: Makefile,v 1.2 2022/08/23 06:45:01 wiz Exp $

DISTNAME=	oculante-0.5.47
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=woelper/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/woelper/oculante/
COMMENT=	Minimalistic crossplatform image viewer written in rust
LICENSE=	mit

BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin share/icons/hicolor/scalable/apps

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/oculante \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
