# $NetBSD: Makefile,v 1.14 2008/03/04 06:59:03 jlam Exp $

DISTNAME=	hands-2.0.bsd386
PKGNAME=	bridge-hands-2.0
CATEGORIES=	games
MASTER_SITES=	http://www.whiteoaks.com/hands/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.whiteoaks.com/hands/
COMMENT=	Generate hands for duplicate bridge

EXTRACT_ELEMENTS=	hands/source

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/hands/source
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}		\
		-o hands hands.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hands ${DESTDIR}${PREFIX}/bin/bridge-hands

.include "../../mk/bsd.pkg.mk"
