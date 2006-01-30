# $NetBSD: Makefile,v 1.53 2006/01/30 18:50:08 joerg Exp $

DISTNAME=	bonobo-1.0.22
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/bonobo/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Architecture for creating reusable software components

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

BUILDLINK_DEPENDS.libxml=	libxml>1.8.15

BROKEN_GETTEXT_DETECTION=	yes
BUILD_USES_MSGFMT=	yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11BASE=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE:Q}
CONFIGURE_ENV+=		X11BASE=${X11BASE:Q}
CONFIGURE_ARGS+=	--enable-gtk-doc=no

PKGCONFIG_OVERRIDE=	libefs/libefs.pc.in

post-install:
	-@${RMDIR} ${PREFIX}/share/libefs/html/libefs
	-@${RMDIR} ${PREFIX}/share/libefs/html
	-@${RMDIR} ${PREFIX}/share/libefs

.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
