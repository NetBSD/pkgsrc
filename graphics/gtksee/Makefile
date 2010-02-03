# $NetBSD: Makefile,v 1.19 2010/02/03 23:03:26 joerg Exp $
#

DISTNAME=		gtksee-0.5.6
PKGREVISION=		5
CATEGORIES=		graphics x11
MASTER_SITES=		http://download.berlios.de/gtksee/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://developer.berlios.de/projects/gtksee/
COMMENT=		Gtk-based image viewing and cataloging program

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	YES

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 share/doc/gtksee

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/gtksee.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gtksee.1
	${INSTALL_DATA} ${WRKSRC}/README  ${DESTDIR}${PREFIX}/share/doc/gtksee
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/gtksee
	${INSTALL_DATA} ${WRKSRC}/TODO	  ${DESTDIR}${PREFIX}/share/doc/gtksee

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
