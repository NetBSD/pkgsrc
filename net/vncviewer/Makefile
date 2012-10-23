# $NetBSD: Makefile,v 1.28 2012/10/23 17:19:17 asau Exp $

DISTNAME=		vnc-4_1_2-unixsrc
PKGNAME=		vncviewer-4.1.2
PKGREVISION=		2
CATEGORIES=		net x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.realvnc.com/
COMMENT=		Viewer for remote X and Win32 VNC servers

CONFLICTS=		tightvnc-[0-9]* tightvncviewer-[0-9]*

WRKSRC=			${WRKDIR}/${DISTNAME}/unix
CRYPTO=			yes
NO_INSTALL_MANPAGES=	yes
USE_LANGUAGES=		c c++
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-installed-zlib

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${DESTDIR}${PREFIX}/bin/vncviewer
	${INSTALL_MAN} ${WRKSRC}/vncviewer/vncviewer.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vncviewer.1
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${DESTDIR}${PREFIX}/bin/vncpasswd
	${INSTALL_MAN} ${WRKSRC}/vncpasswd/vncpasswd.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vncpasswd.1

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
