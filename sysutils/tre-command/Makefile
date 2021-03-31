# $NetBSD: Makefile,v 1.1 2021/03/31 20:20:55 pin Exp $

DISTNAME=	tre-command-0.3.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dduan/}
GITHUB_PROJECT=	tre
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/dduan/tre/
COMMENT=	Tree command, improved
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tre ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
