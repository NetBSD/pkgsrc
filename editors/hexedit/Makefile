# $NetBSD: Makefile,v 1.21 2004/04/11 08:12:34 snj Exp $
#

DISTNAME=	hexedit-1.2.2
PKGREVISION=			2
CATEGORIES=	editors
MASTER_SITES=	http://www.chez.com/prigaux/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.chez.com/prigaux/hexedit.html
COMMENT=	To view and edit files in hexadecimal or ASCII

WRKSRC=		${WRKDIR}/hexedit
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hexedit
.for file in COPYING Changes TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/hexedit
.endfor

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
