# $NetBSD: Makefile,v 1.22 2024/12/16 00:41:19 riastradh Exp $

.include "Makefile.common"

CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Remote helper to use mercurial repositories with git

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_TOOLS+=	gmake pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.curl}/lib

CARGO_NO_DEFAULT_FEATURES=	yes
# version-check is on by default -- disable it for pkgsrc since pkgsrc
# manages version checks and updates, not the software itself, so no
# need for git-cinnabar to phone home every time you run it.
#CARGO_FEATURES+=		version-check

# This has to come before -I/usr/include/krb5 (which comes in on NetBSD
# via curl with gssapi enabled) because both git-core and krb5 have a
# file called `hex.h' which git-core uses internally.
CPPFLAGS+=	-I${WRKSRC}/git-core

INSTALLATION_DIRS+=	libexec/git-core share/doc/git-cinnabar

CHECK_WRKREF_SKIP+=	libexec/git-core/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/git-cinnabar ${DESTDIR}${PREFIX}/libexec/git-core
	cd ${DESTDIR}${PREFIX}/libexec/git-core && ${LN} git-cinnabar git-remote-hg
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/git-cinnabar

CARGO_TEST_ARGS=	test ${DEFAULT_CARGO_ARGS}

do-test: do-test-cargo
do-test-cargo: .PHONY
	@${STEP_MSG} Running cargo test
	${RUN} cd ${CARGO_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo ${CARGO_TEST_ARGS}

TEST_DEPENDS+=		${PYPKGPREFIX}-cram>=0:../../devel/py-cram
TEST_DEPENDS+=		${PYPKGPREFIX}-mercurial>=0:../../devel/py-mercurial

# this.cannot.possibly.exist.invalid-tld appears in some tests that
# check for exact error messages, so let that bypass the fake proxy.
do-test: do-test-cram
do-test-cram: .PHONY
	@${STEP_MSG} Running cram tests
	${RUN} cd ${CARGO_WRKSRC} && \
	${LN} -sf git-cinnabar target/release/git-remote-hg && \
	${SETENV} ${MAKE_ENV} \
	    GIT_EXEC_PATH=${CARGO_WRKSRC}/target/release:"`git --exec-path`" \
	    no_proxy=localhost,this.cannot.possibly.exist.invalid-tld \
	    ${PREFIX}/bin/cram-${PYVERSSUFFIX} ${PKG_VERBOSE:D--verbose} tests

.include "cargo-depends.mk"

.include "../../archivers/zstd/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/rust/cargo.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
