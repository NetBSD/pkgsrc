# $NetBSD: Makefile,v 1.2 2004/02/12 05:49:16 ben Exp $
#

DISTNAME=		llnlxdir2_1_2
PKGNAME=		llnlxdir-2.1.2
WRKSRC=         	${WRKDIR}/llnlxdir2_1_2/sources
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.llnl.gov/pub/ia/llnlxdir/source/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tor@stormwall.org
HOMEPAGE=		http://www.llnl.gov/ia/xdir.html
COMMENT=		Advanced graphical FTP client

USE_BUILDLINK2= 	yes
USE_IMAKE=      	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdir ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XDir.ad ${PREFIX}/lib/X11/app-defaults/XDir

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
