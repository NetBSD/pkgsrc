# $NetBSD: Makefile,v 1.33 2012/10/23 17:19:13 asau Exp $

DISTNAME=		tightvnc-1.3.10
PKGNAME=		${DISTNAME:S/tightvnc/tightvncviewer/}
PKGREVISION=		2
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

CONFIGURE_DIRS=		libvncauth
CONFIGURE_DIRS+=	vncviewer
BUILD_DIRS=		${CONFIGURE_DIRS}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1				\
			lib/X11/app-defaults share/doc/vncviewer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer		\
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vncviewer/vncviewer.man		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vncviewer.1
	${INSTALL_DATA} ${WRKSRC}/vncviewer/Vncviewer			\
		${DESTDIR}${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/vncviewer/README			\
		${DESTDIR}${PREFIX}/share/doc/vncviewer/README

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
