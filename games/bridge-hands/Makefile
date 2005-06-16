# $NetBSD: Makefile,v 1.12 2005/06/16 06:57:53 jlam Exp $

DISTNAME=	hands-2.0.bsd386
PKGNAME=	bridge-hands-2.0
CATEGORIES=	games
MASTER_SITES=	http://www.whiteoaks.com/hands/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.whiteoaks.com/hands/
COMMENT=	Generate hands for duplicate bridge

EXTRACT_ELEMENTS=	hands/source

WRKSRC=			${WRKDIR}/hands/source
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}		\
		-o hands hands.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hands ${PREFIX}/bin/bridge-hands

.include "../../mk/bsd.pkg.mk"
