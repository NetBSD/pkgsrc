# $NetBSD: Makefile,v 1.6 2006/05/18 20:29:58 wiz Exp $

DISTNAME=	fe-1.6
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.moria.de/~michael/fe/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.moria.de/~michael/fe/
COMMENT=	Folding editor

BROKEN_IN=		pkgsrc-2006Q1

GNU_CONFIGURE=	yes
USE_TOOLS+=	msgfmt

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fe
	${INSTALL_DATA} ${WRKSRC}/fe.ps ${PREFIX}/share/doc/fe/fe.ps
	${INSTALL_DATA} ${WRKSRC}/feref.ps ${PREFIX}/share/doc/fe/feref.ps

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
