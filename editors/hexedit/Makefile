# $NetBSD: Makefile,v 1.19 2003/09/28 09:13:56 jlam Exp $
#

DISTNAME=	hexedit-1.2.2
PKGREVISION=			2
WRKSRC=		${WRKDIR}/hexedit
CATEGORIES=	editors
MASTER_SITES=	http://www.chez.com/prigaux/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.chez.com/prigaux/hexedit.html
COMMENT=	To view and edit files in hexadecimal or ASCII

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hexedit
.for file in COPYING Changes TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/hexedit
.endfor

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
