# $NetBSD: Makefile,v 1.11 2002/01/18 22:59:30 mjl Exp $
#

DISTNAME=	hexedit-1.2.2
WRKSRC=		${WRKDIR}/hexedit
CATEGORIES=	editors
MASTER_SITES=	http://www.chez.com/prigaux/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.chez.com/prigaux/hexedit.html
COMMENT=	to view and edit files in hexadecimal or ASCII

GNU_CONFIGURE=		yes
USE_BUILDLINK_ONLY=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hexedit
.for file in COPYING Changes TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/hexedit
.endfor

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
