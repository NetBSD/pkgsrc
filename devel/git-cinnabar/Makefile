# $NetBSD: Makefile,v 1.12 2024/06/14 14:13:33 riastradh Exp $

# does not contain the git submodules, please update GITHUB_SUBMODULES below
.include "Makefile.common"

PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Remote helper to use mercurial repositories with git

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

GITHUB_SUBMODULES=	git-for-windows git v2.41.0.windows.1 git-core

USE_TOOLS+=	gmake pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.curl}/lib

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

do-test:
	${RUN} cd ${CARGO_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo ${CARGO_TEST_ARGS}

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
