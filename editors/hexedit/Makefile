# $NetBSD: Makefile,v 1.5 1999/02/20 22:48:27 hubertf Exp $
#

DISTNAME=	hexedit-1.1.0
WRKSRC=		${WRKDIR}/hexedit
CATEGORIES=	editors
MASTER_SITES=	http://www.chez.com/prigaux/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.chez.com/prigaux/hexedit.html

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${PREFIX}/lib" INSTALL=/usr/bin/install

post-install:
	${MKDIR} ${PREFIX}/share/doc/hexedit
.for file in COPYING Changes TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/hexedit
.endfor

.include "../../mk/bsd.pkg.mk"
