# $NetBSD: Makefile,v 1.10 2023/10/05 20:13:36 pin Exp $

DISTNAME=	hyperfine-1.18.0
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkdp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sharkdp/hyperfine/
COMMENT=	Command-line benchmarking tool
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/hyperfine.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/hyperfine.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
