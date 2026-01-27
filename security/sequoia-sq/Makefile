# $NetBSD: Makefile,v 1.17 2026/01/27 09:51:17 wiz Exp $

DISTNAME=	sequoia-sq-1.3.1
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITLAB:=sequoia-pgp/}
GITLAB_PROJECT=	sequoia-sq
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sequoia-pgp.gitlab.io/user-documentation
COMMENT=	Sequoia-PGP command line tool
LICENSE=	gnu-gpl-v2

# bindgen needs libclang
TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

TOOL_DEPENDS+=	capnproto-[0-9]*:../../devel/capnproto

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/sequoia-sq-v1.3.1-198777869bd9e51d98f0782c2caa605b4dfbdfa5

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.nettle}/lib

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d
INSTALLATION_DIRS+=	share/zsh/site-functions

post-install:
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-sq-*/out/man-pages/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-sq-*/out/shell-completions/sq.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-sq-*/out/shell-completions/sq.fish ${DESTDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-sq-*/out/shell-completions/_sq ${DESTDIR}${PREFIX}/share/zsh/site-functions

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
