# $NetBSD: Makefile,v 1.12 2008/01/12 04:17:38 bjs Exp $

DISTNAME=	fe-1.8
CATEGORIES=	editors
MASTER_SITES=	http://www.moria.de/~michael/fe/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.moria.de/~michael/fe/
COMMENT=	Folding editor

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	msgfmt
BROKEN_GETTEXT_DETECTION=	yes

INSTALLATION_DIRS=	share/doc/fe

post-install:
	${INSTALL_DATA} ${WRKSRC}/fe.ps ${DESTDIR}${PREFIX}/share/doc/fe/fe.ps
	${INSTALL_DATA} ${WRKSRC}/feref.ps ${DESTDIR}${PREFIX}/share/doc/fe/feref.ps

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
