# $NetBSD: Makefile,v 1.4 2008/04/07 17:11:51 joerg Exp $
#

DISTNAME=		fruit_21_linux
PKGNAME=		fruit-2.1
CATEGORIES=		games
MASTER_SITES=		http://arctrix.com/nas/fruit/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://arctrix.com/nas/fruit/
COMMENT=		Chess playing engine

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DIRS=		src
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/fruit ${DESTDIR}${PREFIX}/bin/fruit

.include "../../mk/bsd.pkg.mk"
