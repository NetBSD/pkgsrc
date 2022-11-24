# $NetBSD: Makefile,v 1.3 2022/11/24 15:23:32 pin Exp $

DISTNAME=	bred-0.3.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=manorajesh/}
GITHUB_TAG=	aa99902a2da5f47f99b7bef08a367fb1da68be6f

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
