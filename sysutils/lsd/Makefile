# $NetBSD: Makefile,v 1.6 2022/01/16 16:51:31 pin Exp $

DISTNAME=	lsd-0.21.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Peltoche/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Peltoche/lsd/
COMMENT=	The next gen ls command
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin share/doc/lsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/lsd ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/lsd.md ${DESTDIR}${PREFIX}/share/doc/lsd

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
