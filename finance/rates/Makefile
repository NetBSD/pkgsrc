# $NetBSD: Makefile,v 1.5 2021/05/30 16:54:04 pin Exp $

DISTNAME=	rates-0.5.0
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=lunush/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/lunush/rates/
COMMENT=	Currency exchange rates in your terminal
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rates ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
