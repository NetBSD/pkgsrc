# $NetBSD: Makefile,v 1.2 2022/11/17 09:52:13 pin Exp $

DISTNAME=	bred-0.3.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=manorajesh/}
GITHUB_TAG=	e0c56702f1a986a0976167d883c2a216605eed99

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
