# $NetBSD: Makefile,v 1.12 2004/11/26 21:58:30 snj Exp $
# FreeBSD Id: Makefile,v 1.4 1997/09/08 12:23:55 tg Exp
#

DISTNAME=		9menu-1.8
CATEGORIES=		misc plan9
MASTER_SITES=		ftp://ftp.freefriends.org/arnold/Source/
EXTRACT_SUFX=		.shar.gz

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Simple menu patterned after the plan9 user interface

MAKEFILE=		Makefile.noimake
ALL_TARGET=		9menu
USE_X11=		yes

WRKSRC=			${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9menu ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/9menu.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
