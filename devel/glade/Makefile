# $NetBSD: Makefile,v 1.13 1999/11/08 22:04:42 tron Exp $
# FreeBSD Id: Makefile,v 1.10 1998/11/18 17:35:16 vanilla Exp
#

DISTNAME=	glade-0.5.3
CATEGORIES=	devel
MASTER_SITES=   http://glade.pn.org/ \
		http://www.glade.hhips.de/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://glade.pn.org/

DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
USE_X11BASE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/TODO ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/developer.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/file_format.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/generic.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/manual.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/notes.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/portability.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/source_code.txt ${PREFIX}/share/doc/glade

.include "../../mk/bsd.pkg.mk"
