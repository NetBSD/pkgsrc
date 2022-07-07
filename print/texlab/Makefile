# $NetBSD: Makefile,v 1.7 2022/07/07 19:08:27 wiz Exp $

DISTNAME=	texlab-4.2.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=latex-lsp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/latex-lsp/texlab/
COMMENT=	Implementation of the Language Server Protocol for LaTeX
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

USE_LANGUAGES=		c c++	# Rust, but needs toolchain for linking
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/texlab	\
	  ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/texlab.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
