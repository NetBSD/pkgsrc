# $NetBSD: Makefile,v 1.8 2003/03/29 12:40:41 jmmv Exp $
#

DISTNAME=	xxgdb-1.12
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	rh@trapdoor.vip.at
COMMENT=	graphical X11 interface for gdb

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CPPFLAGS=
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xxgdb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XDbx.ad ${PREFIX}/lib/X11/app-defaults/XDbx
	${INSTALL_DATA} ${WRKSRC}/xxgdb.man ${PREFIX}/man/man1/xxgdb.1

.include "../../mk/bsd.pkg.mk"
