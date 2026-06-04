# $NetBSD: Makefile,v 1.2 2026/06/04 14:07:54 schmonz Exp $

DISTNAME=		yaks-0.2.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=mattwynne/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/mattwynne/yaks/
COMMENT=		Shared Discovery Trees in the CLI for teams of humans and robots
LICENSE=		mit

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config

RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${SSLBASE}/lib

AUTO_MKDIRS=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/completions/yx.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/yx
	${INSTALL_DATA} ${WRKSRC}/completions/yx.zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_yx

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
