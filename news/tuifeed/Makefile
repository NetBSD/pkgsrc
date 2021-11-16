# $NetBSD: Makefile,v 1.1 2021/11/16 08:46:01 pin Exp $

DISTNAME=	tuifeed-0.1.0
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=veeso/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/veeso/tuifeed/
COMMENT=	Terminal feed reader with a fancy ui
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tuifeed ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
