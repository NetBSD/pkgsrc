# $NetBSD: Makefile,v 1.4 2024/12/27 21:30:14 pin Exp $

DISTNAME=	cchmod-0.1.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirryi/}
GITHUB_TAG=	45a65a239ea007210d99d00c1d771cf8d64daede

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirryi/cchmod/
COMMENT=	Chmod calculator
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cchmod \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
