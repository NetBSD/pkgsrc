# $NetBSD: Makefile,v 1.2 2005/12/09 14:17:44 joerg Exp $

DISTNAME=	fe-1.6
CATEGORIES=	editors
MASTER_SITES=	http://www.moria.de/~michael/fe/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.moria.de/~michael/fe/
COMMENT=	Folding editor

GNU_CONFIGURE=	yes
BUILD_USES_MSGFMT=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fe
	${INSTALL_DATA} ${WRKSRC}/fe.ps ${PREFIX}/share/doc/fe/fe.ps
	${INSTALL_DATA} ${WRKSRC}/feref.ps ${PREFIX}/share/doc/fe/feref.ps

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
