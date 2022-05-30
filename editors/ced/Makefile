# $NetBSD: Makefile,v 1.4 2022/05/30 21:27:57 pin Exp $

DISTNAME=	ced-0.1.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=Simhyeon/}
GITHUB_PROJECT=	ced
GITHUB_TAG=	d6152c5b4b076f80c23262eae2966d118a08c87c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Simhyeon/ced/
COMMENT=	Dead easy csv editor
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		cli

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ced \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
