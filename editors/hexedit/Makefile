# $NetBSD: Makefile,v 1.1 1998/08/24 11:58:04 frueauf Exp $
#

DISTNAME=	hexedit-0.9.4
WRKSRC=		${WRKDIR}/hexedit
CATEGORIES=	editors
MASTER_SITES=	http://www.chez.com/prigaux/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.chez.com/prigaux/hexedit.html

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

ALL_TARGET=	# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hexedit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hexedit.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/hexedit
.for file in COPYING Changes TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/hexedit
.endfor

.include "../../mk/bsd.pkg.mk"
