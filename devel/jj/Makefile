# $NetBSD: Makefile,v 1.31 2025/08/10 10:44:02 wiz Exp $

DISTNAME=	jj-0.32.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jj-vcs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jj-vcs/jj
COMMENT=	Git-compatible DVCS that is both simple and powerful
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d
INSTALLATION_DIRS+=	share/zsh/site-functions

post-build:
	for shell in bash fish zsh; do \
		${WRKSRC}/target/release/jj util completion $$shell > ${WRKDIR}/$$shell; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/jj \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/jj
	${INSTALL_DATA} ${WRKDIR}/fish \
		${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/jj.fish
	${INSTALL_DATA} ${WRKDIR}/zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_jj

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
