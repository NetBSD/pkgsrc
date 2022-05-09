# $NetBSD: Makefile,v 1.3 2022/05/09 21:48:48 pin Exp $

DISTNAME=	tuifeed-0.1.1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=veeso/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/veeso/tuifeed/
COMMENT=	Terminal feed reader with a fancy ui
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tuifeed \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
