# $NetBSD: Makefile,v 1.3 2022/01/03 12:19:38 pin Exp $

DISTNAME=	kalker-1.1.0
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

USE_LANGUAGES+=	c c++	# rust, but needs a toolchain to link
USE_TOOLS+=	m4

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/kalker ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
