# $NetBSD: Makefile,v 1.2 2022/04/30 21:56:56 pin Exp $

DISTNAME=	difftastic-0.28.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Wilfred/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/Wilfred/difftastic/
COMMENT=	Syntax-aware diffing tool
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++17

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/difft \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
