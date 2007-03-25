# $NetBSD: Makefile,v 1.24 2007/03/25 22:06:02 tron Exp $

DISTNAME=		tightvnc-1.2.9
PKGNAME=		${DISTNAME:S/tightvnc/tightvncviewer/}
PKGREVISION=	2
CATEGORIES=		net x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vnc-tight/}
DISTFILES=		${DISTNAME}_unixsrc.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tightvnc.com/
COMMENT=		Viewer for remote X and Win32 VNC servers

CONFLICTS=		vncviewer-[0-9]*

WRKSRC=			${WRKDIR}/vnc_unixsrc
CRYPTO=			yes
USE_IMAKE=		yes

CONFIGURE_DIRS=		${WRKSRC}/libvncauth
CONFIGURE_DIRS+=	${WRKSRC}/vncviewer
BUILD_DIRS=		${CONFIGURE_DIRS}
INSTALL_DIRS=		${WRKSRC}/vncviewer
INSTALLATION_DIRS=	lib/X11/app-defaults share/doc/vncviewer

post-install:
	${INSTALL_DATA} ${WRKSRC}/vncviewer/Vncviewer			\
		${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/vncviewer/README			\
		${PREFIX}/share/doc/vncviewer/README

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
