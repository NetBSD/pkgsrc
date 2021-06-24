# $NetBSD: Makefile,v 1.31 2021/06/24 15:23:42 pin Exp $

DISTNAME=	xplr-0.14.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sayanarijit/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sayanarijit/xplr/
COMMENT=	Hackable, minimal, fast TUI file explorer
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c
USE_TOOLS+=	pkg-config bash:run

INSTALLATION_DIRS=	bin share/examples/xplr

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.LuaJIT2}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.LuaJIT2}/lib
MAKE_ENV+=	RUSTFLAGS=${RUSTFLAGS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/xplr ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/init.lua ${DESTDIR}${PREFIX}/share/examples/xplr

.include "../../lang/rust/cargo.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
