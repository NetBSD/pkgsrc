# $NetBSD: Makefile,v 1.14 2025/06/19 20:24:27 wiz Exp $

DISTNAME=	kalker-2.2.1.20250421
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=PaddiM8/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	b8ef87ac271e11cc10f65e4ece76070ce742796a

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kalker.strct.net/
COMMENT=	CLI calculator supporting math-like syntax with user-defined variables
LICENSE=	mit

PREV_PKGPATH=	math/kalk
CONFLICTS+=	kalk-[0-9]*
SUPERSEDES+=	kalk-[0-9]*

.include "cargo-depends.mk"

#RUST_REQ=	1.80.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.80.1 on amd64
USE_LANGUAGES+=	c c++
USE_TOOLS+=	m4

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/kalker \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
