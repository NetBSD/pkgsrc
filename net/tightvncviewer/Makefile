# $NetBSD: Makefile,v 1.9 2003/03/03 02:45:51 jschauma Exp $
# FreeBSD Id: Makefile,v 1.2 1998/03/19 01:54:59 msmith Exp
#

DISTNAME=		tightvnc-1.2.8
PKGNAME=		tightvncviewer-1.2.8
PKGREVISION=		1
CATEGORIES=		net x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vnc-tight/}
DISTFILES=		${DISTNAME}_unixsrc.tar.bz2

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www.tightvnc.com/
COMMENT=		Viewer for remote X and Win32 VNC servers

CONFLICTS=		vncviewer-[0-9]*

CRYPTO=			yes
USE_BUILDLINK2=		yes
USE_IMAKE=		yes

WRKSRC=			${WRKDIR}/vnc_unixsrc
CONFIGURE_DIRS=		${WRKSRC}/libvncauth
CONFIGURE_DIRS+=	${WRKSRC}/vncviewer
BUILD_DIRS=		${CONFIGURE_DIRS}
INSTALL_DIRS=		${WRKSRC}/vncviewer

post-install:
	${INSTALL_DATA} ${WRKSRC}/vncviewer/Vncviewer			\
		${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vncviewer
	${INSTALL_DATA} ${WRKSRC}/vncviewer/README			\
		${PREFIX}/share/doc/vncviewer/README

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
