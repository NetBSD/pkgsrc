# $NetBSD: Makefile,v 1.1 1998/08/18 09:25:16 frueauf Exp $
#

DISTNAME=		xboing2.4
PKGNAME=		xboing-2.4
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=		root@garbled.net

DEPENDS+=		xpm-3.4k:../../graphics/xpm

WRKSRC=			${WRKDIR}/xboing
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

post-install:
	chown bin:games ${X11BASE}/bin/xboing
	chmod 2755 ${X11BASE}/bin/xboing
	${INSTALL_MAN} ${WRKSRC}/xboing.man ${X11BASE}/man/man6/xboing.6

.include "../../mk/bsd.pkg.mk"
