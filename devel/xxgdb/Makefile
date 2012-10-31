# $NetBSD: Makefile,v 1.18 2012/10/31 11:19:55 asau Exp $
#

DISTNAME=	xxgdb-1.12
PKGREVISION=	2
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphical X11 interface for gdb

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CPPFLAGS=
.endif

INSTALLATION_DIRS=	bin lib/X11/app-defaults ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xxgdb ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XDbx.ad ${DESTDIR}${PREFIX}/lib/X11/app-defaults/XDbx
	${INSTALL_DATA} ${WRKSRC}/xxgdb.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xxgdb.1

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
