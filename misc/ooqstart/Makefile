# $NetBSD: Makefile,v 1.12 2004/03/26 02:27:46 wiz Exp $
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
DEPENDS+=	xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

USE_BUILDLINK2=	YES
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

.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
