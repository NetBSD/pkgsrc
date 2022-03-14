# $NetBSD: Makefile,v 1.7 2022/03/14 10:24:40 pin Exp $

# lok >= 0.1.5 (currently 0.2.0) requires rust-1.59.0
DISTNAME=	lok-0.1.4
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=wyhaya/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/wyhaya/lok/
COMMENT=	Count the number of codes
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/lok \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
