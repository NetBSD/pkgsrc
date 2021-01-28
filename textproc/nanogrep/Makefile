# $NetBSD: Makefile,v 1.3 2021/01/28 15:20:58 pin Exp $

DISTNAME=	nanogrep-2.2.0
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
