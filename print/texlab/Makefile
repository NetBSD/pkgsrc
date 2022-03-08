# $NetBSD: Makefile,v 1.5 2022/03/08 09:25:17 wiz Exp $

DISTNAME=	texlab-3.3.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=latex-lsp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/latex-lsp/texlab/
COMMENT=	Implementation of the Language Server Protocol for LaTeX
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
# https://github.com/zotero/citeproc-rs/issues/61
CITEPROC_REV=	2ab195a1e6f84f0ff284813ece61dc62096abbfe
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
