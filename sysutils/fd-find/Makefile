# $NetBSD: Makefile,v 1.12 2023/12/28 20:43:52 pin Exp $

DISTNAME=	fd-find-9.0.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkdp/}
GITHUB_PROJECT=	fd
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	milan@petabyte.dev
HOMEPAGE=	https://github.com/sharkdp/fd/
COMMENT=	Simple, fast und user-friendly alternative to find
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/fd \
		${DESTDIR}${PREFIX}/bin/fdfind
	${INSTALL_MAN} ${WRKSRC}/doc/fd.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/fdfind.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
