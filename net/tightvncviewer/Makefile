# $NetBSD: Makefile,v 1.3 2002/02/12 07:11:26 martti Exp $
# FreeBSD Id: Makefile,v 1.2 1998/03/19 01:54:59 msmith Exp
#

DISTNAME=		tightvnc-1.2.2
PKGNAME=		tightvncviewer-1.2.2
CATEGORIES=		net x11
MASTER_SITES=		http://prdownloads.sourceforge.net/vnc-tight/
DISTFILES=		tightvnc-1.2.2_unixsrc.tar.bz2

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www.tightvnc.com/
COMMENT=		Viewer for remote X and Win32 VNC servers

CONFLICTS=		vncviewer-[0-9]*

CRYPTO=			yes
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

WRKSRC=			${WRKDIR}/vnc_unixsrc

post-patch:
	${TOUCH} ${WRKSRC}/vncviewer/vncviewer.man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vncviewer
	${INSTALL_DATA} ${WRKSRC}/vncviewer/README ${PREFIX}/share/doc/vncviewer/README

.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
