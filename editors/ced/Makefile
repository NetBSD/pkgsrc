# $NetBSD: Makefile,v 1.2 2022/04/18 20:12:56 pin Exp $

DISTNAME=	ced-0.1.4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=Simhyeon/}
GITHUB_PROJECT=	ced
GITHUB_TAG=	85171f742ff2587657be78988d734c28c483eec7

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
