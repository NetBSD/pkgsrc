# $NetBSD: Makefile,v 1.3 2022/04/25 19:32:32 pin Exp $

DISTNAME=	ced-0.1.5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=Simhyeon/}
GITHUB_PROJECT=	ced
GITHUB_TAG=	b536921835242aa345b8be0145f0f8d8bce7fecb

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
