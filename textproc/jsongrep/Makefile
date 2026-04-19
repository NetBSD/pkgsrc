# $NetBSD: Makefile,v 1.4 2026/04/19 16:08:20 pin Exp $

DISTNAME=	jsongrep-0.9.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=micahkepe/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/micahkepe/jsongrep/
COMMENT=	Path query language over JSON documents
LICENSE=	mit

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/zsh/site-functions

post-build:
	cd ${WRKSRC} && target/release/jg generate shell bash > jg.bash
	cd ${WRKSRC} && target/release/jg generate shell zsh > jg.zsh
	cd ${WRKSRC} && target/release/jg generate man -o .

post-install:
	cd ${WRKSRC} && ${INSTALL_MAN} *.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC} && ${INSTALL_DATA} jg.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions/jg
	cd ${WRKSRC} && ${INSTALL_DATA} jg.zsh ${DESTDIR}${PREFIX}/share/zsh/site-functions/_jg

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
