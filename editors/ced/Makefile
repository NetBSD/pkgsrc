# $NetBSD: Makefile,v 1.5 2022/06/04 21:24:58 pin Exp $

DISTNAME=	ced-0.1.7
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=Simhyeon/}
GITHUB_PROJECT=	ced
GITHUB_TAG=	76f18843436d05e58d9f7194acd098aa17826314

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
