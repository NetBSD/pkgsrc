# $NetBSD: Makefile,v 1.6 2021/08/03 09:00:37 pin Exp $

DISTNAME=	rates-0.5.0
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=lunush/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/lunush/rates/
COMMENT=	Currency exchange rates in your terminal
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rates ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
