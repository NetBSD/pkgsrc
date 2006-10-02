# $NetBSD: Makefile,v 1.1.1.1 2006/10/02 20:05:20 rillig Exp $
#

DISTNAME=		fruit_21_linux
PKGNAME=		fruit-2.1
CATEGORIES=		games
MASTER_SITES=		http://arctrix.com/nas/fruit/
EXTRACT_SUFX=		.zip

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://arctrix.com/nas/fruit/
COMMENT=		Chess playing engine

BUILD_DIRS=		src
USE_LANGUAGES=		c++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/fruit ${PREFIX}/bin/fruit

.include "../../mk/bsd.pkg.mk"
