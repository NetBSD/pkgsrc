# $NetBSD: Makefile,v 1.9 2003/07/21 16:43:48 martti Exp $
#

DISTNAME=	xxgdb-1.12
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	rh@trapdoor.vip.at
COMMENT=	Graphical X11 interface for gdb

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
