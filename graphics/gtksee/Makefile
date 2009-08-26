# $NetBSD: Makefile,v 1.17 2009/08/26 19:57:43 sno Exp $
#

DISTNAME=		gtksee-0.5.6
PKGREVISION=		4
CATEGORIES=		graphics x11
MASTER_SITES=		http://download.berlios.de/gtksee/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://developer.berlios.de/projects/gtksee/
COMMENT=		Gtk-based image viewing and cataloging program

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/gtksee.1 ${PREFIX}/${PKGMANDIR}/man1/gtksee.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gtksee
	${INSTALL_DATA} ${WRKSRC}/README  ${PREFIX}/share/doc/gtksee
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/gtksee
	${INSTALL_DATA} ${WRKSRC}/TODO	  ${PREFIX}/share/doc/gtksee

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
