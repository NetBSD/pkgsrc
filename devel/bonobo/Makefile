# $NetBSD: Makefile,v 1.26 2002/07/18 02:19:39 rh Exp $
#

DISTNAME=		bonobo-1.0.18
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/bonobo/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Architecture for creating reusable software components

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

BUILDLINK_DEPENDS.ORBit=ORBit>0.5.8
BUILDLINK_DEPENDS.libxml=libxml>1.8.15

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=		X11BASE="${X11BASE}"

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

post-patch:
	for file in `${FIND} ${WRKSRC} -name "Makefile.in"`; do		\
		${SED}	-e "s|-I\$$(includedir)||g"			\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../graphics/gdk-pixbuf-gnome/buildlink.mk"
.include "../../graphics/freetype2/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../devel/popt/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
