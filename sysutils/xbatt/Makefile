# $NetBSD: Makefile,v 1.2 2000/06/26 16:44:22 dmcmahill Exp $
#

DISTNAME=	xbatt-1.3pr1
WRKSRC=		${WRKDIR}/xbatt-1.3
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www2.clave.gr.jp/~eto/xbatt/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www2.clave.gr.jp/~eto/xbatt/	# Not really

.if !exists(/usr/include/machine/apmvar.h")
IGNORE+=	"APM is not available for ${MACHINE_PLATFORM}"                  
.endif

DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_IMAKE=	yes
ALL_TARGET=	xbatt

post-install:
		${INSTALL_DATA} ${FILESDIR}/XBatt ${X11BASE}/lib/X11/app-defaults/XBatt
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/xbatt
		${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/xbatt
		${INSTALL_MAN} ${WRKSRC}/README.jp ${PREFIX}/share/doc/xbatt

.include "../../mk/bsd.pkg.mk"
