# $NetBSD: Makefile,v 1.2 1998/08/27 22:08:37 frueauf Exp $
#

DISTNAME=	hexedit-0.9.5
WRKSRC=		${WRKDIR}/hexedit
CATEGORIES=	editors
MASTER_SITES=	http://www.chez.com/prigaux/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.chez.com/prigaux/hexedit.html

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

CONFLICTS=	hexedit-0.9.4

ALL_TARGET=	# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hexedit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hexedit.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/hexedit
.for file in COPYING Changes TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/hexedit
.endfor

.include "../../mk/bsd.pkg.mk"
