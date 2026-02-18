# $NetBSD: Makefile,v 1.30 2026/02/18 08:00:55 wiz Exp $

DISTNAME=	xbatt-1.3pr1
PKGNAME=	xbatt-1.3.1
PKGREVISION=	4
CATEGORIES=	sysutils x11
MASTER_SITES=	#http://www.clave.gr.jp/~eto/xbatt/

MAINTAINER=	hubertf@NetBSD.org
#HOMEPAGE=	http://www.clave.gr.jp/~eto/xbatt/
COMMENT=	Displays battery status of your notebook via APM

PKG_DESTDIR_SUPPORT=	destdir

.if !exists(/usr/include/machine/apmvar.h)
PKG_FAIL_REASON+=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

WRKSRC=		${WRKDIR}/xbatt-1.3
USE_IMAKE=	YES
BUILD_TARGET=	xbatt

INSTALLATION_DIRS=	lib/X11/app-defaults share/doc/xbatt

post-install:
	${INSTALL_DATA} ${FILESDIR}/XBatt ${DESTDIR}${PREFIX}/lib/X11/app-defaults/XBatt
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xbatt
	${INSTALL_MAN} ${WRKSRC}/README.jp ${DESTDIR}${PREFIX}/share/doc/xbatt

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
