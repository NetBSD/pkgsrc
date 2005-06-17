# $NetBSD: Makefile,v 1.13 2005/06/17 03:50:29 jlam Exp $

DISTNAME=       	vnc-3.3.3r2_unixsrc
PKGNAME=		vncviewer-3.3.3.2
PKGREVISION=		1
CATEGORIES=		net x11
MASTER_SITES=   	http://www.uk.research.att.com/archive/vnc/dist/
EXTRACT_SUFX=		.tgz

PATCH_SITES=		ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=		vnc-3.3.3r2-v6-20010421.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	 	abs@NetBSD.org
HOMEPAGE=		http://www.uk.research.att.com/vnc/
COMMENT=		Viewer for remote X and Win32 VNC servers

WRKSRC=			${WRKDIR}/vnc_unixsrc
CRYPTO=			yes
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes
BUILD_DEFS+=		USE_INET6

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vncviewer
	${INSTALL_DATA} ${WRKSRC}/vncviewer/README ${PREFIX}/share/doc/vncviewer

.include "../../mk/bsd.pkg.mk"
