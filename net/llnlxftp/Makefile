# $NetBSD: Makefile,v 1.1.1.1 2004/02/12 05:48:30 ben Exp $
#

DISTNAME=		llnlxftp2.1
PKGNAME=		llnlxftp-2.1
WRKSRC=         	${WRKDIR}/llnlxftp2.1/sources
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.llnl.gov/pub/ia/llnlxftp/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tor@stormwall.org
HOMEPAGE=		http://www.llnl.gov/ia/xftp.html
COMMENT=		Motif FTP client

USE_BUILDLINK2= 	yes
USE_IMAKE=      	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xftp ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XFtp.ad ${PREFIX}/lib/X11/app-defaults/XFtp

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
