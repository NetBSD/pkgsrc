# $NetBSD: Makefile,v 1.4 2006/03/04 21:29:31 jlam Exp $

DISTNAME=	fe-1.6
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.moria.de/~michael/fe/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
