# $NetBSD: Makefile,v 1.50 2004/10/03 00:13:27 tv Exp $

DISTNAME=	glade-0.6.4
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNOME:=sources/glade/0.6/}

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=	http://glade.gnome.org/
COMMENT=	User interface builder for GTK+

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_X11BASE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-bonobo

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

.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
