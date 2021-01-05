# $NetBSD: Makefile,v 1.2 2021/01/05 19:19:47 pin Exp $

DISTNAME=	lsd-0.19.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Peltoche/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Peltoche/lsd/
COMMENT=	The next gen ls command
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=		c	# rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/lsd ${DESTDIR}${PREFIX}/bin


.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
