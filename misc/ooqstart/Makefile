# $NetBSD: Makefile,v 1.15 2004/04/26 22:34:17 snj Exp $
#

DISTNAME=	ooqstart-0.8.3
PKGREVISION=	7
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ooqstart/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ooqstart.sourceforge.net/
COMMENT=	OpenOffice quickstart applet for GNOME

DEPENDS+=	gnome-applets>=1.4.0:../../x11/gnome-applets

USE_BUILDLINK3=	YES
USE_DIRS+=	xdg-1.1
USE_GNU_TOOLS+=	make
USE_X11BASE=	YES
NO_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ooqstart_applet ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ooqstart.png ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gnome/ooqstart_applet.desktop		\
		${PREFIX}/share/applets/Utility
	${INSTALL_DATA} ${WRKSRC}/gnome/ooqstart_applet.gnorba		\
		${PREFIX}/etc/CORBA/servers
	${INSTALL_DATA_DIR} ${PREFIX}/gnome/help/ooqstart_applet/C
.for help in index.html license.txt panel.png
	${INSTALL_DATA} ${WRKSRC}/help/${help}				\
		${PREFIX}/gnome/help/ooqstart_applet/C
.endfor

.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
