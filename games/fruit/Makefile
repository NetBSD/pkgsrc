# $NetBSD: Makefile,v 1.6 2012/10/06 11:54:39 asau Exp $
#

DISTNAME=		fruit_21_linux
PKGNAME=		fruit-2.1
CATEGORIES=		games
MASTER_SITES=		http://arctrix.com/nas/chess/fruit/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://arctrix.com/nas/chess/fruit/
COMMENT=		Chess playing engine

BUILD_DIRS=		src
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/fruit ${DESTDIR}${PREFIX}/bin/fruit

.include "../../mk/bsd.pkg.mk"
