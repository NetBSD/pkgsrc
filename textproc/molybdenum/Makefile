# $NetBSD: Makefile,v 1.5 2021/08/18 21:01:43 pin Exp $

DISTNAME=	molybdenum-0.1.6
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
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/mo ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
