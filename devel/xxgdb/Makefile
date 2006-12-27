# $NetBSD: Makefile,v 1.13 2006/12/27 13:37:36 joerg Exp $
#

DISTNAME=	xxgdb-1.12
PKGREVISION=	1
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	rh@trapdoor.vip.at
COMMENT=	Graphical X11 interface for gdb

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CPPFLAGS=
.endif

INSTALLATION_DIRS=	bin lib/X11/app-defaults man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xxgdb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XDbx.ad ${PREFIX}/lib/X11/app-defaults/XDbx
	${INSTALL_DATA} ${WRKSRC}/xxgdb.man ${PREFIX}/man/man1/xxgdb.1

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
