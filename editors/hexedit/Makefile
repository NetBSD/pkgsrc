# $NetBSD: Makefile,v 1.9 2001/02/16 14:40:50 wiz Exp $
#

DISTNAME=	hexedit-1.1.0
WRKSRC=		${WRKDIR}/hexedit
CATEGORIES=	editors
MASTER_SITES=	http://www.chez.com/prigaux/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.chez.com/prigaux/hexedit.html
COMMENT=	to view and edit files in hexadecimal or ASCII

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib	# for -lncurses

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hexedit
.for file in COPYING Changes TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/hexedit
.endfor

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	ncurses>=4.2:../../devel/ncurses
.endif

.include "../../mk/bsd.pkg.mk"
