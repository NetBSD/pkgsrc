# $NetBSD: Makefile,v 1.3 2001/02/17 18:19:53 wiz Exp $
# FreeBSD Id: Makefile,v 1.2 1998/03/19 01:54:59 msmith Exp
#

DISTNAME=       	vnc-3.3.3r2_unixsrc
PKGNAME=		vncviewer-3.3.3.2
CATEGORIES=		net x11
MASTER_SITES=   	http://www.uk.research.att.com/vnc/dist/
EXTRACT_SUFX=		.tgz

MAINTAINER=	 	abs@netbsd.org
HOMEPAGE=		http://www.uk.research.att.com/vnc/
COMMENT=		Viewer for remote X and Win32 VNC servers

CRYPTO=			yes
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

WRKSRC=			${WRKDIR}/vnc_unixsrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${MKDIR} ${PREFIX}/share/doc/vncviewer
	${INSTALL_DATA} ${WRKSRC}/vncviewer/README ${PREFIX}/share/doc/vncviewer/README

.include "../../mk/bsd.pkg.mk"
