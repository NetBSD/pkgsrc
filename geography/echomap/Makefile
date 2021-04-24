# $NetBSD: Makefile,v 1.2 2021/04/24 19:41:09 pin Exp $

DISTNAME=	echomap-0.6.0
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=pjsier/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pjsier/echomap/
COMMENT=	Preview map files in the terminal
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/echomap ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
