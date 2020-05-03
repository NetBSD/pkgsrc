# $NetBSD: Makefile,v 1.16 2020/05/03 16:06:01 rillig Exp $

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

# harmless; only indexes 0..51 are used.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}		\
		-o hands hands.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hands ${DESTDIR}${PREFIX}/bin/bridge-hands

.include "../../mk/bsd.pkg.mk"
