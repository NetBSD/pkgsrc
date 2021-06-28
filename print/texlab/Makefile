# $NetBSD: Makefile,v 1.2 2021/06/28 10:42:49 wiz Exp $

DISTNAME=	texlab-3.2.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=latex-lsp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/latex-lsp/texlab/
COMMENT=	Implementation of the Language Server Protocol for LaTeX
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
CITEPROC_REV=	68c7a7c16088b5d7751641ab37299ad064cdb221
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
