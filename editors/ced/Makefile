# $NetBSD: Makefile,v 1.6 2022/06/28 09:29:17 pin Exp $

DISTNAME=	ced-0.2.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=Simhyeon/}
GITHUB_PROJECT=	ced
GITHUB_TAG=	e54b8674607a6a39b03756cc11be3b9b8886e111

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
