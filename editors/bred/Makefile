# $NetBSD: Makefile,v 1.1 2022/10/09 16:12:17 pin Exp $

DISTNAME=	bred-0.2.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=manorajesh/}
GITHUB_TAG=	86810429b9e2d590b45d3d58b8863e2850d0e80f

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/manorajesh/bred/
COMMENT=	Simple binary file reader
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/bred \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
