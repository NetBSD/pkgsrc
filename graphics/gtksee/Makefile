# $NetBSD: Makefile,v 1.5 2004/10/03 00:14:52 tv Exp $
#

DISTNAME=		gtksee-0.5.2
PKGREVISION=		2
CATEGORIES=		graphics x11
MASTER_SITES=		http://download.berlios.de/gtksee/

MAINTAINER=		drue@users.sf.net
HOMEPAGE=		http://developer.berlios.de/projects/gtksee/
COMMENT=		Gtk-based image viewing and cataloging program

BUILD_USES_MSGFMT=	YES
BUILDLINK_DEPENDS.gtk?=	gtk+>=1.2.10

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES

post-install:
	${INSTALL_MAN} ${FILESDIR}/gtksee.1 ${PREFIX}/man/man1/gtksee.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gtksee
	${INSTALL_DATA} ${WRKSRC}/README  ${PREFIX}/share/doc/gtksee
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/gtksee
	${INSTALL_DATA} ${WRKSRC}/TODO	  ${PREFIX}/share/doc/gtksee

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
