# $NetBSD: Makefile,v 1.26 2002/07/17 12:45:29 rh Exp $
# FreeBSD Id: Makefile,v 1.10 1998/11/18 17:35:16 vanilla Exp
#

DISTNAME=	glade-0.6.2
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=   http://glade.pn.org/ \
		${MASTER_SITE_GNOME:=stable/sources/glade/}

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://glade.pn.org/
COMMENT=	User interface builder for GTK+

GNU_CONFIGURE=	yes
USE_X11BASE=	yes

#CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ENV+=	LOCALEDIR=${PKGLOCALEDIR}
CONFIGURE_ARGS+=--with-bonobo
CONFIGURE_ARGS+=--localstatedir=${X11PREFIX}/var/lib

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/developer.txt ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/file_format.txt ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/generic.txt ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/manual.txt ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/notes.txt ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/portability.txt ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/source_code.txt ${PREFIX}/share/doc/glade

.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
