# $NetBSD: Makefile,v 1.11 2010/02/11 22:05:43 joerg Exp $
#

DISTNAME=		llnlxftp2.1
PKGNAME=		llnlxftp-2.1
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.llnl.gov/pub/ia/llnlxftp/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tor@stormwall.org
HOMEPAGE=		http://www.llnl.gov/icc/sdd/img/xftp.html
COMMENT=		Motif FTP client

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/llnlxftp2.1/sources
INSTALLATION_DIRS=	bin lib/X11/app-defaults

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xftp ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XFtp.ad ${DESTDIR}${PREFIX}/lib/X11/app-defaults/XFtp

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
