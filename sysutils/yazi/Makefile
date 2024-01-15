# $NetBSD: Makefile,v 1.4 2024/01/15 21:09:42 pin Exp $

DISTNAME=	yazi-0.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sxyazi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sxyazi/yazi/
COMMENT=	Blazing fast terminal file manager
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin share/examples/yazi

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.LuaJIT2}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.LuaJIT2}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/yazi \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/yazi-config/preset/keymap.toml \
		${DESTDIR}${PREFIX}/share/examples/yazi
	${INSTALL_DATA} ${WRKSRC}/yazi-config/preset/theme.toml \
		${DESTDIR}${PREFIX}/share/examples/yazi
	${INSTALL_DATA} ${WRKSRC}/yazi-config/preset/yazi.toml \
		${DESTDIR}${PREFIX}/share/examples/yazi

.include "../../lang/rust/cargo.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
