# $NetBSD: Makefile,v 1.6 2004/01/20 12:15:39 agc Exp $

DISTNAME=	hands-2.0.bsd386
PKGNAME=	bridge-hands-2.0
CATEGORIES=	games
MASTER_SITES=	http://www.whiteoaks.com/hands/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.whiteoaks.com/hands/
COMMENT=	Generate hands for duplicate bridge

EXTRACT_ELEMENTS=	hands/source

WRKSRC=			${WRKDIR}/hands/source
USE_BUILDLINK2=		# defined

do-build:
	cd ${WRKSRC}; ${BUILDLINK_CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}	\
		-o hands hands.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hands ${PREFIX}/bin/bridge-hands

.include "../../mk/bsd.pkg.mk"
