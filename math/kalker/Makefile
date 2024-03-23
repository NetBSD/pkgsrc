# $NetBSD: Makefile,v 1.9 2024/03/23 19:10:49 pin Exp $

DISTNAME=	kalker-2.1.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=PaddiM8/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://kalker.strct.net/
COMMENT=	CLI calculator supporting math-like syntax with user-defined variables
LICENSE=	mit

PREV_PKGPATH=	math/kalk
CONFLICTS+=	kalk-[0-9]*
SUPERSEDES+=	kalk-[0-9]*

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	m4

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/kalker \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
