# $NetBSD: Makefile,v 1.2 2021/04/24 19:38:39 pin Exp $

DISTNAME=	ddiff-0.1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=biosan/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
