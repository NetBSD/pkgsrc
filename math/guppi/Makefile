# $NetBSD: Makefile,v 1.19 2002/09/10 16:06:45 wiz Exp $

DISTNAME=	Guppi-0.40.3
PKGNAME=	${DISTNAME:S/G/g/}
PKGREVISION=	1
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/Guppi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/guppi/
COMMENT=	Plot program with integrated statistics capabilities

# "guppi" only accepts newer versions of the "gnumeric" package which
# cannot be build on all platforms. We only enable "gnumeric" support
# on platforms which can build the "gnumeric" 1.0.x packages.
.if exists(/usr/include/wctype.h)
DEPENDS+=	gnumeric>=1.0.9:../../math/gnumeric

CONFIGURE_ARGS=	--enable-gnumeric
PLIST_SUBST+=	GNUMERIC=
.else
CONFIGURE_ARGS=	--disable-gnumeric
PLIST_SUBST+=	GNUMERIC="@comment "
.endif
DEPENDS+=	guile>=1.4:../../lang/guile

BUILDLINK_DEPENDS.gnome-core=		gnome-core>=1.4.0.4nb1
BUILDLINK_DEPENDS.gdk-pixbuf=		gdk-pixbuf>=0.11.0nb1
BUILDLINK_DEPENDS.gdk-pixbuf-gnome=	gdk-pixbuf-gnome>=0.11.0nb1

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/libguppi.m4 \
	  ${LOCALBASE}/share/aclocal/libguppi.m4

.include "../../devel/libglade/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
