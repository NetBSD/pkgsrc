# $NetBSD: Makefile,v 1.13 2025/04/11 09:09:35 pin Exp $

DISTNAME=	tlrc-1.11.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=tldr-pages/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tldr.sh/
COMMENT=	Tldr client written in Rust
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

SITES.wasi-0.11.0+wasi-snapshop-preview1.crate=	https://static.crates.io/crates/wasi/

.include "cargo-depends.mk"

RUST_REQ=		1.74.0
INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/tldr.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tldr.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
