# $NetBSD: Makefile,v 1.4 2022/01/22 16:12:49 pin Exp $

DISTNAME=	echomap-0.6.2
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=pjsier/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/pjsier/echomap/
COMMENT=	Preview map files in the terminal
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/echomap ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
