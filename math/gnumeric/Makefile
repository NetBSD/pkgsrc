# $NetBSD: Makefile,v 1.51 2002/07/03 07:41:17 lukem Exp $
#

DISTNAME=		gnumeric-1.0.7
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnumeric/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/gnumeric/
COMMENT=		Spreadsheet program from the GNOME project

# wctype.h is found on NetBSD 1.5R and later
ONLY_FOR_PLATFORM=	NetBSD-1.5[R-Z]-* NetBSD-1.5Z[A-Z]-* NetBSD-1.[6-9]*-*

# for Python support a shared libpython is required but not provided yet
#BUILD_DEPENDS+=		python>=2.0:../../lang/python

BUILDLINK_DEPENDS.gtk=		gtk+>=1.2.7
BUILDLINK_DEPENDS.libole2=	libole2>=0.2.4
BUILDLINK_DEPENDS.gnome-print=	gnome-print>=0.29
BUILDLINK_DEPENDS.bonobo=	bonobo>=1.0.9
BUILDLINK_DEPENDS.oaf=		oaf>=0.6.2
BUILDLINK_DEPENDS.libglade=	libglade>=0.16
BUILDLINK_DEPENDS.gal=		gal>=0.16

DEPENDS+=		scrollkeeper-[0-9]*:../../textproc/scrollkeeper

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_PERL5=		YES

LDFLAGS+=      		-L${LOCALBASE}/lib
LDFLAGS+=      		-Wl,-R${LOCALBASE}/lib
LDFLAGS+=      		-lunicode
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--without-guile		# needs CVS-only guile-1.5
CONFIGURE_ARGS+=	--without-python
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-configure:
	for i in ${WRKSRC}/plugins/*/Makefile.in ; do			\
		${SED} <$$i >$$i.fixed					\
		  -e 's/^\(COMPILE.*\)\\$$/\1 $${EXTRA_GNOME_CFLAGS} \\/' \
		  -e 's/^\(COMPILE.*[^\\]\)$$/\1 $${EXTRA_GNOME_CFLAGS}/' && \
		${MV} $$i.fixed $$i ;					\
	done

.include "../../print/gnome-print/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/libole2/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
