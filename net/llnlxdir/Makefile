# $NetBSD: Makefile,v 1.3 2004/04/25 08:39:24 snj Exp $
#

DISTNAME=		llnlxdir2_1_2
PKGNAME=		llnlxdir-2.1.2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.llnl.gov/pub/ia/llnlxdir/source/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tor@stormwall.org
HOMEPAGE=		http://www.llnl.gov/ia/xdir.html
COMMENT=		Advanced graphical FTP client

USE_BUILDLINK3= 	yes
USE_IMAKE=      	yes
WRKSRC=         	${WRKDIR}/llnlxdir2_1_2/sources

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdir ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XDir.ad ${PREFIX}/lib/X11/app-defaults/XDir

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
