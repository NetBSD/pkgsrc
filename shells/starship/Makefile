# $NetBSD: Makefile,v 1.7 2022/01/14 15:38:07 pin Exp $

DISTNAME=	starship-1.2.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=starship/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/starship/starship/
COMMENT=	Fast, customizable cross-shell prompt
LICENSE=	isc

# The libc and rust-battery crates currently have limited platform support
ONLY_FOR_PLATFORM=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*

.include "cargo-depends.mk"

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

# Disable all battery features on NetBSD
# See https://github.com/svartalf/rust-battery/issues/20
# and https://github.com/svartalf/rust-battery/issues/33
# The new fork at starship/rust-battery does not address issues
# with NetBSD support, hence disable both.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
CARGO_NO_DEFAULT_FEATURES=	YES
.endif

INSTALLATION_DIRS=	bin
EGDIR=			${PREFIX}/share/examples/starship/auto-completion

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/starship ${DESTDIR}${PREFIX}/bin
	${WRKSRC}/target/release/starship completions bash > ${DESTDIR}${EGDIR}/starship.bash
	${WRKSRC}/target/release/starship completions fish > ${DESTDIR}${EGDIR}/starship.fish
	${WRKSRC}/target/release/starship completions zsh > ${DESTDIR}${EGDIR}/_starship

DEPENDS+=		git-base-[0-9]*:../../devel/git-base

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
