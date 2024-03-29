# $NetBSD: Makefile,v 1.6 2024/03/29 22:06:15 pin Exp $

DISTNAME=	tlrc-1.9.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=tldr-pages/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://tldr.sh/
COMMENT=	Tldr client written in Rust
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/tldr.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tldr.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
