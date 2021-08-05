# $NetBSD: Makefile,v 1.2 2021/08/05 08:56:47 pin Exp $

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

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tre ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
