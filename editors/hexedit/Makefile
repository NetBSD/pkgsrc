# $NetBSD: Makefile,v 1.3 1998/09/28 10:35:48 frueauf Exp $
#

DISTNAME=	hexedit-1.0.0
WRKSRC=		${WRKDIR}/hexedit
CATEGORIES=	editors
MASTER_SITES=	http://www.chez.com/prigaux/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.chez.com/prigaux/hexedit.html

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

CONFLICTS=	hexedit-0.9.4 hexedit-0.9.5

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${PREFIX}/lib"

post-install:
	${MKDIR} ${PREFIX}/share/doc/hexedit
.for file in COPYING Changes TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/hexedit
.endfor

.include "../../mk/bsd.pkg.mk"
