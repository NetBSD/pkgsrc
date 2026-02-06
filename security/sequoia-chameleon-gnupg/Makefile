# $NetBSD: Makefile,v 1.8 2026/02/06 10:05:51 wiz Exp $

DISTNAME=	sequoia-chameleon-gnupg-0.13.1
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITLAB:=sequoia-pgp/}
GITLAB_PROJECT=	sequoia-chameleon-gnupg
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/sequoia-pgp/sequoia-chameleon-gnupg
COMMENT=	Sequoia's reimplementation of the GnuPG interface
LICENSE=	gnu-gpl-v3

# bindgen needs libclang
TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/sequoia-chameleon-gnupg-v0.13.1-6fbe6d0fba83d5324ddf66a45cd349a458044b58

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.nettle}/lib

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d
INSTALLATION_DIRS+=	share/zsh/site-functions

post-install:
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-chameleon-gnupg-*/out/man-pages/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-chameleon-gnupg-*/out/shell-completions/gpg-sq.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-chameleon-gnupg-*/out/shell-completions/gpgv-sq.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-chameleon-gnupg-*/out/shell-completions/gpg-sq.fish ${DESTDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-chameleon-gnupg-*/out/shell-completions/gpgv-sq.fish ${DESTDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-chameleon-gnupg-*/out/shell-completions/_gpg-sq ${DESTDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-chameleon-gnupg-*/out/shell-completions/_gpgv-sq ${DESTDIR}${PREFIX}/share/zsh/site-functions

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
