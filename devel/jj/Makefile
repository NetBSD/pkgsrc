# $NetBSD: Makefile,v 1.46 2026/10/08 10:28:11 wiz Exp $

DISTNAME=	jj-0.46.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jj-vcs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jj-vcs/jj
COMMENT=	Git-compatible DVCS that is both simple and powerful
LICENSE=	apache-2.0

DEPENDS+=	git-base>=2.42.0:../../devel/git-base

# status as of 0.46.0
# failures:
#     test_run_command::test_run_pool_size_from_jobs_flag
#     test_run_command::test_run_sets_workspace_root_env_var
#     test_run_command::test_run_sparse
# test result: FAILED. 1134 passed; 3 failed; 0 ignored; 0 measured; 0 filtered out; finished in 50.98s
#
# upstream bug report:
# https://github.com/jj-vcs/jj/issues/10342

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
