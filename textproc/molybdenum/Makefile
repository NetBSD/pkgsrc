# $NetBSD: Makefile,v 1.7 2022/09/17 15:51:50 pin Exp $

DISTNAME=	molybdenum-0.1.9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=gfannes/}
GITHUB_TAG=	release-v${PKGVERSION_NOREV}

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
