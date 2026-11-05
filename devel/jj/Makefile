# $NetBSD: Makefile,v 1.47 2026/11/05 09:32:37 wiz Exp $

DISTNAME=	jj-0.47.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jj-vcs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jj-vcs/jj
COMMENT=	Git-compatible DVCS that is both simple and powerful
LICENSE=	apache-2.0

DEPENDS+=	git-base>=2.42.0:../../devel/git-base

# status as of 0.47.1
# all tests pass

RUST_REQ=	1.97.1

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

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} cargo test

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
