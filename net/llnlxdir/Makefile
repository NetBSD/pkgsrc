# $NetBSD: Makefile,v 1.4 2004/10/03 00:17:55 tv Exp $
#

DISTNAME=		llnlxdir2_1_2
PKGNAME=		llnlxdir-2.1.2
PKGREVISION=	1
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
