# $NetBSD: Makefile,v 1.8 2025/04/02 11:06:37 pin Exp $

DISTNAME=	tuifeed-0.3.2
# 0.4.1 requires Rust >= 1.85
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=veeso/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/veeso/tuifeed/
COMMENT=	Terminal feed reader with a fancy ui
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
NOT_FOR_PLATFORM+=	*-*-i386

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tuifeed \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
