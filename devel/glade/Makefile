# $NetBSD: Makefile,v 1.42 2003/11/12 01:31:48 salo Exp $

DISTNAME=	glade-0.6.4
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNOME:=sources/glade/0.6/}

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=	http://glade.gnome.org/
COMMENT=	User interface builder for GTK+

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11BASE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

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

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
