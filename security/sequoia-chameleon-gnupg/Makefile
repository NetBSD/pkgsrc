# $NetBSD: Makefile,v 1.1 2025/03/06 22:56:20 wiz Exp $

DISTNAME=	sequoia-chameleon-gnupg-0.12.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITLAB:=sequoia-pgp/}
GITLAB_PROJECT=	sequoia-chameleon-gnupg
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/sequoia-pgp/sequoia-chameleon-gnupg
COMMENT=	Sequoia's reimplementation of the GnuPG interface
LICENSE=	gnu-gpl-v3

#TOOL_DEPENDS+=	capnproto-[0-9]*:../../devel/capnproto

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/sequoia-chameleon-gnupg-v0.12.0-bba1ced319eb4cd34d937392054d9d0ea0838243

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.nettle}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.clang}/lib

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
.include "../../lang/clang/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
