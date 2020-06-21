# $NetBSD: Makefile,v 1.16 2020/06/21 04:09:24 mef Exp $

DISTNAME=	fe-1.9
CATEGORIES=	editors
MASTER_SITES=	http://www.moria.de/~michael/fe/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.moria.de/~michael/fe/
COMMENT=	Folding editor
LICENSE=	gnu-gpl-v1

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
