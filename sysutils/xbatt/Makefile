# $NetBSD: Makefile,v 1.9 2001/11/29 01:12:48 hubertf Exp $
#

DISTNAME=	xbatt-1.3pr1
PKGNAME=	xbatt-1.3.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/xbatt-1.3
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www2.clave.gr.jp/~eto/xbatt/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www2.clave.gr.jp/~eto/xbatt/	# Not really
COMMENT=	Displays battery status of your notebook via APM

.if !exists(/usr/include/machine/apmvar.h)
IGNORE+=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

USE_IMAKE=	YES
USE_XPM=	YES
ALL_TARGET=	xbatt

post-install:
		${INSTALL_DATA} ${FILESDIR}/XBatt ${X11PREFIX}/lib/X11/app-defaults/XBatt
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/xbatt
		${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/xbatt
		${INSTALL_MAN} ${WRKSRC}/README.jp ${PREFIX}/share/doc/xbatt

.include "../../mk/bsd.pkg.mk"
