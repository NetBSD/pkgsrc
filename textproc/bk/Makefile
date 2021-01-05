# $NetBSD: Makefile,v 1.2 2021/01/05 09:52:21 pin Exp $

DISTNAME=	bk-0.5.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aeosynth/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/aeosynth/bk/
COMMENT=	Terminal Epub reader
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=			c	# rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/bk ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
