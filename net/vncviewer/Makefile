# $NetBSD: Makefile,v 1.7 2002/08/21 02:12:16 grant Exp $
# FreeBSD Id: Makefile,v 1.2 1998/03/19 01:54:59 msmith Exp
#

DISTNAME=       	vnc-3.3.3r2_unixsrc
PKGNAME=		vncviewer-3.3.3.2
PKGREVISION=		1
CATEGORIES=		net x11
MASTER_SITES=   	http://www.uk.research.att.com/vnc/dist/
EXTRACT_SUFX=		.tgz

PATCH_SITES=		ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=		vnc-3.3.3r2-v6-20010421.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	 	abs@netbsd.org
HOMEPAGE=		http://www.uk.research.att.com/vnc/
COMMENT=		Viewer for remote X and Win32 VNC servers

CRYPTO=			yes
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes
BUILD_DEFS+=		USE_INET6

WRKSRC=			${WRKDIR}/vnc_unixsrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vncviewer
	${INSTALL_DATA} ${WRKSRC}/vncviewer/README ${PREFIX}/share/doc/vncviewer

.include "../../mk/bsd.pkg.mk"
