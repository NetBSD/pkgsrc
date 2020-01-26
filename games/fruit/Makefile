# $NetBSD: Makefile,v 1.7 2020/01/26 17:31:15 rillig Exp $
#

DISTNAME=		fruit_21_linux
PKGNAME=		fruit-2.1
CATEGORIES=		games
MASTER_SITES=		http://arctrix.com/nas/chess/fruit/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://arctrix.com/nas/chess/fruit/
COMMENT=		Chess playing engine

BUILD_DIRS=		src
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/fruit ${DESTDIR}${PREFIX}/bin/fruit

.include "../../mk/bsd.pkg.mk"
