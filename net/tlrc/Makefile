# $NetBSD: Makefile,v 1.9 2025/02/08 15:21:17 pin Exp $

DISTNAME=	tlrc-1.10.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=tldr-pages/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://tldr.sh/
COMMENT=	Tldr client written in Rust
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.74.0
INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/tldr.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tldr.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
