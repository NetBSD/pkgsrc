# $NetBSD: Makefile,v 1.23 2004/04/21 15:01:28 jmmv Exp $
#

DISTNAME=		anjuta-1.2.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=anjuta/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.anjuta.org/
COMMENT=		Gnome based IDE for C and C++

DEPENDS+=		autoconf>=2.59:../../devel/autoconf
DEPENDS+=		automake>=1.8.2:../../devel/automake
DEPENDS+=		gettext>=0.11.5:../../devel/gettext
DEPENDS+=		glade2>=2.6.0:../../devel/glade2
DEPENDS+=		gmake>=3.80:../../devel/gmake
DEPENDS+=		gnome2-terminal>=2.4.2:../../x11/gnome2-terminal
DEPENDS+=		libtool>=1.5.2:../../devel/libtool
DEPENDS+=		pkgconfig>=0.15.0:../../devel/pkgconfig
DEPENDS+=		yelp>=2.4.2:../../misc/yelp

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

SUBST_CLASSES+=		make
SUBST_STAGE.make=	pre-configure
SUBST_MESSAGE.make=	"Fixing path to GNU make."
SUBST_FILES.make=	data/properties/anjuta.properties
SUBST_FILES.make+=	src/defaults.c
SUBST_SED.make=		-e 's|make=make|make=${GMAKE}|'

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
