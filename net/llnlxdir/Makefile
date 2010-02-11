# $NetBSD: Makefile,v 1.12 2010/02/11 22:05:00 joerg Exp $
#

DISTNAME=		llnlxdir2_1_2
PKGNAME=		llnlxdir-2.1.2
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.llnl.gov/pub/ia/llnlxdir/source/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tor@stormwall.org
HOMEPAGE=		http://www.llnl.gov/icc/sdd/img/xdir.html
COMMENT=		Advanced graphical FTP client

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/llnlxdir2_1_2/sources
INSTALLATION_DIRS=	bin lib/X11/app-defaults

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdir ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XDir.ad ${DESTDIR}${PREFIX}/lib/X11/app-defaults/XDir

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
