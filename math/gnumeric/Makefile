# $NetBSD: Makefile,v 1.55 2002/07/16 13:21:34 wiz Exp $
#

DISTNAME=		gnumeric-1.0.7
PKGREVISION=		1
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

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_PERL5=		YES
USE_BUILDLINK_ONLY=	YES

LDFLAGS+=      		-Wl,-R${LOCALBASE}/lib
LDFLAGS+=      		-lunicode
CONFIGURE_ARGS+=	--without-guile		# needs CVS-only guile-1.5
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-psiconv
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-configure:
	for i in ${WRKSRC}/plugins/*/Makefile.in ; do			\
		${SED} <$$i >$$i.fixed					\
		  -e 's/^\(COMPILE.*\)\\$$/\1 $${EXTRA_GNOME_CFLAGS} \\/' \
		  -e 's/^\(COMPILE.*[^\\]\)$$/\1 $${EXTRA_GNOME_CFLAGS}/' && \
		${MV} $$i.fixed $$i ;					\
	done

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/libole2/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../textproc/libunicode/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../textproc/scrollkeeper/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
