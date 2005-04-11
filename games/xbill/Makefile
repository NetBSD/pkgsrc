# $NetBSD: Makefile,v 1.15 2005/04/11 21:45:58 tv Exp $
#

DISTNAME=		xbill-2.0
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xbill.org/
COMMENT=		Stop the dreaded Windows virus from infecting computers

CONFLICT=		gnome-games-[0-9]*

USE_IMAKE=		YES
USE_PKGINSTALL=		YES
NO_INSTALL_MANPAGES=	YES

PKG_GROUPS=		games
MAKE_DIRS_PERMS+=	/var/games ${BINOWN} games 0775
SUPPORT_FILES_PERMS+=	${PREFIX}/share/examples/xbill.scores /var/games/xbill.scores ${BINOWN} games 0664

post-install:
	${INSTALL_MAN} ${WRKSRC}/xbill.man ${PREFIX}/man/man6/xbill.6
	${INSTALL_DATA} ${WRKSRC}/scores ${PREFIX}/share/examples/xbill.scores

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
