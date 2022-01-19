# $NetBSD: Makefile,v 1.1 2022/01/19 10:57:57 pin Exp $

DISTNAME=	hcal-0.3.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=0xflotus/}
GITHUB_PROJECT=	hcal
GITHUB_TAG=	150e887011ce6f6f978d2d8d042ef6ba045908a1

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/0xflotus/hcal/
COMMENT=	Hexadecimal calendar in terminal for programmers
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/hcal ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
