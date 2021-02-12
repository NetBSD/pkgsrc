# $NetBSD: Makefile,v 1.1 2021/02/12 13:42:12 pin Exp $

DISTNAME=	ddiff-0.1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=biosan/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/biosan/ddiff/
COMMENT=	Compare directories
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ddiff ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
