# $NetBSD: Makefile,v 1.11 2025/03/05 11:12:38 wiz Exp $

DISTNAME=	sequoia-sq-1.2.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITLAB:=sequoia-pgp/}
GITLAB_PROJECT=	sequoia-sq
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sequoia-pgp.gitlab.io/user-documentation
COMMENT=	Sequoia-PGP command line tool
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	capnproto-[0-9]*:../../devel/capnproto

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/sequoia-sq-v1.2.0-e507fc4ad98639f33c11a8614941ca6380607a72

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
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-sq-*/out/man-pages/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-sq-*/out/shell-completions/sq.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-sq-*/out/shell-completions/sq.fish ${DESTDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-sq-*/out/shell-completions/_sq ${DESTDIR}${PREFIX}/share/zsh/site-functions

.include "../../lang/rust/cargo.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
