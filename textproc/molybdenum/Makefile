# $NetBSD: Makefile,v 1.6 2022/05/12 20:21:16 pin Exp $

DISTNAME=	molybdenum-0.1.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=gfannes/}
GITHUB_PROJECT=	molybdenum
GITHUB_TAG=	8515c20610c3fd04537897f662fb5e6a83bfad97

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/gfannes/molybdenum/
COMMENT=	Recursive search and replace CLI application
LICENSE=	eupl-v1.1

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/mo \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
