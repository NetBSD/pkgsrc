# $NetBSD: Makefile,v 1.4 2002/06/30 14:04:26 jschauma Exp $
#

DISTNAME=		atk-1.0.2
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.0/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.0/ \
			http://www.ameth.org/gimp/pub/gtk/v2.0/ \
			${MASTER_SITE_GNOME:=stable/sources/atk/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://developer.gnome.org/projects/gap/
COMMENT=		Set of interfaces for accessibility

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_GMAKE=		yes
# glib-mkenums overflows a 2048kb stack on atkobject.h 
UNLIMIT_RESOURCES=	stacksize

.include "../../devel/glib2/buildlink.mk"
.include "../../devel/pkgconfig/buildlink.mk"
.include "../../converters/libiconv/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
