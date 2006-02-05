# $NetBSD: Makefile,v 1.12 2006/02/05 23:09:33 joerg Exp $
#

DISTNAME=		gtksee-0.5.6
PKGREVISION=		2
CATEGORIES=		graphics x11
MASTER_SITES=		http://download.berlios.de/gtksee/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://developer.berlios.de/projects/gtksee/
COMMENT=		Gtk-based image viewing and cataloging program

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/gtksee.1 ${PREFIX}/man/man1/gtksee.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gtksee
	${INSTALL_DATA} ${WRKSRC}/README  ${PREFIX}/share/doc/gtksee
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/gtksee
	${INSTALL_DATA} ${WRKSRC}/TODO	  ${PREFIX}/share/doc/gtksee

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
