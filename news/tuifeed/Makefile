# $NetBSD: Makefile,v 1.7 2025/03/27 10:08:01 pin Exp $

DISTNAME=	tuifeed-0.3.2
# 0.4.1 requires Rust >= 1.85
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
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tuifeed \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
