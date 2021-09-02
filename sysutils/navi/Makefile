# $NetBSD: Makefile,v 1.10 2021/09/02 11:28:55 pin Exp $

DISTNAME=	navi-2.17.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=denisidoro/}
GITHUB_PROJECT=	navi
GITHUB_TAG=	6f4e04c6fc885d06cc09f29414d605c493007e37

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/denisidoro/navi/
COMMENT=	Interactive cheatsheet tool for the CLI and application launchers
LICENSE=	apache-2.0

.include "cargo-depends.mk"

DEPENDS+=	fzf-[0-9]*:../../sysutils/fzf

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/navi ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
