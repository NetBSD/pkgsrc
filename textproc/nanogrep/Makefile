# $NetBSD: Makefile,v 1.2 2021/01/15 08:52:39 pin Exp $

DISTNAME=	nanogrep-2.1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Uniminin/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Uniminin/nanogrep/
COMMENT=	Custom Implementation of minigrep with additional functionality
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c # rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ng ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
