# $NetBSD: Makefile,v 1.2 2000/01/10 00:57:17 wiz Exp $
#

DISTNAME=	mp
PKGNAME=	mp-3.4.0
CATEGORIES=	print
MASTER_SITES=	http://java.sun.com/people/richb/RichApps/mp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     kim@tac.nyc.ny.us
HOMEPAGE=	http://java.sun.com/people/richb/

WRKSRC=		${WRKDIR}/mpdist

NO_CONFIGURE=	yes

USE_X11=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
EXTRALIBS=	-lsocket -lnsl -lgen
.else
BSD_PRINT=	-DBSD_PRINT
.endif

ALL_TARGET=	mp PREFIX=${PREFIX} X11BASE=${X11BASE} CC='${CC}' \
		BSD_PRINT=${BSD_PRINT} EXTRALIBS='${EXTRALIBS}'

INSTALL_TARGET=	install-mp PREFIX=${PREFIX}

pre-patch:
	${CP} ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
