# $NetBSD: Makefile,v 1.3 2021/11/01 11:53:25 wiz Exp $

DISTNAME=	texlab-3.3.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=latex-lsp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/latex-lsp/texlab/
COMMENT=	Implementation of the Language Server Protocol for LaTeX
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
CITEPROC_REV=	5252fbd8d2046a5a7d5cdcee6c6cb39bd0f1a7f3
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	citeproc-rs-${CITEPROC_REV}.tar.gz
SITES.citeproc-rs-${CITEPROC_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=cormacrelf/}citeproc-rs/archive/${CITEPROC_REV}.tar.gz

USE_LANGUAGES=		c c++	# Rust, but needs toolchain for linking
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-extract:
	mv ${WRKDIR}/citeproc-rs* ${WRKDIR}/citeproc-rs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/texlab	\
	  ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/texlab.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
