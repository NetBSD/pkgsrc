# $NetBSD: Makefile,v 1.9 2003/06/04 09:02:28 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/09/08 12:23:55 tg Exp
#

DISTNAME=		9menu-1.6
CATEGORIES=		misc plan9
MASTER_SITES=		ftp://ftp.freefriends.org/arnold/Source/
PATCH_SITES=		http://www1.informatik.uni-erlangen.de/tree/Persons/bauer/new/
PATCHFILES=		9menu-1.6.key.patch
EXTRACT_SUFX=		.shar.gz

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		Simple menu patterned after the plan9 user interface

MAKEFILE=		Makefile.noimake
ALL_TARGET=		9menu
USE_X11=		yes

PATCH_DIST_STRIP=	-p1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9menu ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/9menu.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
