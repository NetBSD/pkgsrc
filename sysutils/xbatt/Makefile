# $NetBSD: Makefile,v 1.1.1.1 1999/10/31 21:16:07 hubertf Exp $
#

DISTNAME=	xbatt-1.3pr1
WRKSRC=		${WRKDIR}/xbatt-1.3
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www2.clave.gr.jp/~eto/xbatt/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www2.clave.gr.jp/~eto/xbatt/	# Not really

DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_IMAKE=	yes
ALL_TARGET=	xbatt

post-install:
		${INSTALL_DATA} ${FILESDIR}/XBatt ${X11BASE}/lib/X11/app-defaults/XBatt
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/xbatt
		${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/xbatt
		${INSTALL_MAN} ${WRKSRC}/README.jp ${PREFIX}/share/doc/xbatt

.include "../../mk/bsd.pkg.mk"
