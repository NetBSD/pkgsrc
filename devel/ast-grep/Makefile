# $NetBSD: Makefile,v 1.36 2024/10/30 18:48:19 pin Exp $

DISTNAME=	ast-grep-0.29.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ast-grep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ast-grep.github.io/
COMMENT=	CLI tool for code structural search, lint, and rewriting
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.67.0
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sg \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ast-grep \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
