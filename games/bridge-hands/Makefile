# $NetBSD: Makefile,v 1.4 2003/07/17 21:37:57 grant Exp $

DISTNAME=	hands-2.0.bsd386
PKGNAME=	bridge-hands-2.0
WRKSRC=		${WRKDIR}/hands/source
CATEGORIES=	games
MASTER_SITES=	http://www.whiteoaks.com/hands/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.whiteoaks.com/hands/
COMMENT=	generate hands for duplicate bridge

EXTRACT_ELEMENTS=	hands/source

USE_BUILDLINK2=		# defined

do-build:
	cd ${WRKSRC}; ${BUILDLINK_CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}	\
		-o hands hands.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hands ${PREFIX}/bin/bridge-hands

.include "../../mk/bsd.pkg.mk"
