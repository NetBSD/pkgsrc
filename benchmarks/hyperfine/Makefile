# $NetBSD: Makefile,v 1.13 2025/11/20 08:43:40 pin Exp $

DISTNAME=	hyperfine-1.20.0
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkdp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sharkdp/hyperfine/
COMMENT=	Command-line benchmarking tool
LICENSE=	apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.88.0

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/hyperfine.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/hyperfine.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
