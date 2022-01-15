# $NetBSD: Makefile,v 1.2 2022/01/15 16:43:10 pin Exp $

DISTNAME=	ugdb-0.1.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ftilde/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/ftilde/ugdb/
COMMENT=	Alternative TUI for gdb
LICENSE=	mit

BUILD_DEPENDS+=		cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ugdb ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "NetBSD" || ${X11_TYPE} == "modular"
DEPENDS+=	gdb-[0-9]*:../../devel/gdb
.endif

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
