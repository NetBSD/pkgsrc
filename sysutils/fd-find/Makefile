# $NetBSD: Makefile,v 1.20 2026/08/27 09:54:33 wiz Exp $

DISTNAME=	fd-find-10.5.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkdp/}
GITHUB_PROJECT=	fd
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	milan@petabyte.dev
HOMEPAGE=	https://github.com/sharkdp/fd/
COMMENT=	Simple, fast und user-friendly alternative to find
LICENSE=	apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.90.0
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/fd \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/fd.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/fd.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
