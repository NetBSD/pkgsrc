# $NetBSD: Makefile,v 1.3 2003/03/29 12:41:00 jmmv Exp $

DISTNAME=	hands-2.0.bsd386
PKGNAME=	bridge-hands-2.0
WRKSRC=		${WRKDIR}/hands/source
CATEGORIES=	games
MASTER_SITES=	http://www.whiteoaks.com/hands/

MAINTAINER=	jlam@netbsd.org
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
