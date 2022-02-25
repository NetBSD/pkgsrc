# $NetBSD: Makefile,v 1.8 2022/02/25 07:27:00 pin Exp $

DISTNAME=	rates-0.7.0
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=lunush/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lunush/rates/
COMMENT=	Currency exchange rates in your terminal
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rates \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
