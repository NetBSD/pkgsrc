# $NetBSD: Makefile,v 1.7 2023/04/11 08:39:19 pin Exp $

DISTNAME=	echomap-0.7.3
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=pjsier/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pjsier/echomap/
COMMENT=	Preview map files in the terminal
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/echomap \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
