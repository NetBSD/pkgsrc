# $NetBSD: Makefile,v 1.15 2002/04/12 13:02:52 jlam Exp $

DISTNAME=	Guppi-0.40.0
PKGNAME=	${DISTNAME:S/G/g/}
PKGREVISION=	1
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/Guppi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/guppi/
COMMENT=	Plot program with integrated statistics capabilities

DEPENDS+=	gnumeric>=0.75:../../math/gnumeric0
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

CONFIGURE_ENV+=	PYTHONBIN=${PYTHONBIN}
MAKE_ENV+=	PYTHONBIN=${PYTHONBIN}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/libguppi.m4 \
	  ${LOCALBASE}/share/aclocal/libguppi.m4

.include "../../lang/python/application.buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
