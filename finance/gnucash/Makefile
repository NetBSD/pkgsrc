# $NetBSD: Makefile,v 1.27 2002/09/10 18:30:43 wiz Exp $
#

DISTNAME=		gnucash-1.6.8
PKGREVISION=		1
CATEGORIES=		finance
MASTER_SITES=		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Personal double-entry accounting program

DEPENDS+=			swig-1.1p5:../../devel/swig
BUILDLINK_DEPENDS.g-wrap=	g-wrap>=1.1.11:../../devel/g-wrap
BUILDLINK_DEPENDS.g-wrap+=	g-wrap<1.3.0:../../devel/g-wrap
BUILDLINK_DEPENDS.guppi=	guppi>=0.35.1:../../math/guppi
BUILDLINK_DEPENDS.popt=		popt>=1.5:../../devel/popt
BUILDLINK_DEPENDS.glib=		glib>=0.99.7:../../devel/glib
BUILDLINK_DEPENDS.guile=	guile>=1.3.4:../../lang/guile
BUILDLINK_DEPENDS.guile+=	guile<1.5.0:../../lang/guile
BUILDLINK_DEPENDS.gdk-pixbuf=	gdk-pixbuf>=0.2.5:../../graphics/gdk-pixbuf
BUILDLINK_DEPENDS.gnome-print=	gnome-print>=0.21:../../print/gnome-print
BUILD_DEPENDS+=			bison>=1.28:../../devel/bison

USE_GMAKE=		YES
USE_LIBTOOL=		YES
#LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_BUILDLINK_ONLY=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-perl-includes=${PERL5_ARCHLIB}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_DIR}

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD)
CPPFLAGS+=		-I${WRKSRC}/include

post-extract:
	${MKDIR} ${WRKSRC}/include
	${LN} -s /usr/include/db.h ${WRKSRC}/include/db_185.h
.if !exists(/usr/include/wctype.h)
	${TOUCH} ${WRKSRC}/include/wctype.h
.endif
.endif

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../devel/g-wrap/buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../devel/popt/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../lang/guile/buildlink.mk"
.include "../../math/guppi/buildlink.mk"
.include "../../net/ORBit/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../www/gtkhtml/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"

.include "../../mk/x11.buildlink.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
