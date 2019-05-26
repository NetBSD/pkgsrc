# $NetBSD: Makefile,v 1.36 2019/05/26 17:11:36 leot Exp $

DISTNAME=		tightvnc-1.3.10
PKGNAME=		${DISTNAME:S/tightvnc/tightvncviewer/}
PKGREVISION=		2
CATEGORIES=		net x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vnc-tight/}
DISTFILES=		${DISTNAME}_unixsrc.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tightvnc.com/
COMMENT=		Viewer for remote X and Win32 VNC servers
LICENSE=		gnu-gpl-v2

CONFLICTS=		vncviewer-[0-9]*

WRKSRC=			${WRKDIR}/vnc_unixsrc
USE_IMAKE=		yes

MAKE_FLAGS+=		CCOPTIONS=${CFLAGS:Q}
MAKE_FLAGS+=		LOCAL_LDFLAGS=${LDFLAGS:Q}

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
