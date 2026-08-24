# $NetBSD: Makefile,v 1.89 2026/08/24 08:48:22 wiz Exp $
#
# Changelog:
# https://github.com/ast-grep/ast-grep/blob/main/CHANGELOG.md

DISTNAME=	ast-grep-0.45.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ast-grep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ast-grep.github.io/
COMMENT=	CLI tool for code structural search, lint, and rewriting
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.85.0
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d
INSTALLATION_DIRS+=	share/zsh/site-functions

post-build:
	for shell in bash fish zsh; do \
		${WRKSRC}/target/release/ast-grep completions $$shell > ${WRKDIR}/$$shell; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sg \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ast-grep \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/ast-grep
	${INSTALL_DATA} ${WRKDIR}/fish \
		${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/ast-grep.fish
	${INSTALL_DATA} ${WRKDIR}/zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_ast-grep

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
