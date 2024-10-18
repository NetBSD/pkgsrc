# $NetBSD: Makefile,v 1.34 2024/10/18 08:53:14 pin Exp $

DISTNAME=	starship-1.21.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=starship/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/starship/starship/
COMMENT=	Fast, customizable cross-shell prompt
LICENSE=	isc

BUILD_DEPENDS+=		cmake-[0-9]*:../../devel/cmake
DEPENDS+=		git-base-[0-9]*:../../devel/git-base

# The libc and rust-battery crates currently have limited platform support
ONLY_FOR_PLATFORM=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*

.include "cargo-depends.mk"

RUST_REQ=	1.80.1
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

INSTALLATION_DIRS=	bin
EGDIR=			${PREFIX}/share/examples/starship/auto-completion

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/starship ${DESTDIR}${PREFIX}/bin
	${WRKSRC}/target/release/starship completions bash > ${DESTDIR}${EGDIR}/starship.bash
	${WRKSRC}/target/release/starship completions fish > ${DESTDIR}${EGDIR}/starship.fish
	${WRKSRC}/target/release/starship completions zsh > ${DESTDIR}${EGDIR}/_starship

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
