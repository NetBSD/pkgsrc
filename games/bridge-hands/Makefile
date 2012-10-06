# $NetBSD: Makefile,v 1.15 2012/10/06 11:54:32 asau Exp $

DISTNAME=	hands-2.0.bsd386
PKGNAME=	bridge-hands-2.0
CATEGORIES=	games
MASTER_SITES=	http://www.whiteoaks.com/hands/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.whiteoaks.com/hands/
COMMENT=	Generate hands for duplicate bridge

EXTRACT_ELEMENTS=	hands/source

WRKSRC=			${WRKDIR}/hands/source
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}		\
		-o hands hands.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hands ${DESTDIR}${PREFIX}/bin/bridge-hands

.include "../../mk/bsd.pkg.mk"
