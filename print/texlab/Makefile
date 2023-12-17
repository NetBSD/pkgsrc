# $NetBSD: Makefile,v 1.15 2023/12/17 22:44:41 wiz Exp $

DISTNAME=	texlab-5.12.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=latex-lsp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/latex-lsp/texlab/
COMMENT=	Implementation of the Language Server Protocol for LaTeX
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

USE_LANGUAGES=		c c++
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/texlab	\
	  ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
