# $NetBSD: Makefile,v 1.2 2001/09/27 23:18:33 jlam Exp $
# FreeBSD Id: Makefile,v 1.2 1998/03/19 01:54:59 msmith Exp
#

DISTNAME=		tightvnc-1.2.0
PKGNAME=		tightvncviewer-1.2.0
CATEGORIES=		net x11
MASTER_SITES=		http://prdownloads.sourceforge.net/vnc-tight/
DISTFILES=		tightvnc-1.2.0_unixsrc.tar.bz2

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www.tightvnc.com/
COMMENT=		Viewer for remote X and Win32 VNC servers

CONFLICTS=		vncviewer-[0-9]*

CRYPTO=			yes
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

WRKSRC=			${WRKDIR}/vnc_unixsrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vncviewer
	${INSTALL_DATA} ${WRKSRC}/vncviewer/README ${PREFIX}/share/doc/vncviewer/README

.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
