# $NetBSD: Makefile,v 1.31 2002/11/30 23:21:35 salo Exp $
#

DISTNAME=	glade-0.6.2
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=   http://glade.pn.org/ \
		${MASTER_SITE_GNOME:=sources/glade/0.6/}

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://glade.pn.org/
COMMENT=	User interface builder for GTK+

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-bonobo
CONFIGURE_ARGS+=	--localstatedir=${SCROLLKEEPER_DATADIR}

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

.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
