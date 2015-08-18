# $NetBSD: Makefile,v 1.15 2015/08/18 07:31:06 wiz Exp $

DISTNAME=	fe-1.8
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.moria.de/~michael/fe/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.moria.de/~michael/fe/
COMMENT=	Folding editor

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
