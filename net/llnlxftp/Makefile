# $NetBSD: Makefile,v 1.3 2004/10/03 00:17:55 tv Exp $
#

DISTNAME=		llnlxftp2.1
PKGNAME=		llnlxftp-2.1
PKGREVISION=	1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.llnl.gov/pub/ia/llnlxftp/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tor@stormwall.org
HOMEPAGE=		http://www.llnl.gov/ia/xftp.html
COMMENT=		Motif FTP client

USE_BUILDLINK3= 	yes
USE_IMAKE=      	yes
WRKSRC=         	${WRKDIR}/llnlxftp2.1/sources

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xftp ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XFtp.ad ${PREFIX}/lib/X11/app-defaults/XFtp

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
