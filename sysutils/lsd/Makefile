# $NetBSD: Makefile,v 1.3 2021/03/07 16:46:37 pin Exp $

DISTNAME=	lsd-0.20.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Peltoche/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Peltoche/lsd/
COMMENT=	The next gen ls command
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=		c	# rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin share/doc/lsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/lsd ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/lsd.md ${DESTDIR}${PREFIX}/share/doc/lsd

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
