# $NetBSD: Makefile,v 1.10 2002/10/30 03:09:27 rh Exp $
#

DISTNAME=		atk-1.0.3
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.0/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.0/ \
			http://www.ameth.org/gimp/pub/gtk/v2.0/ \
			${MASTER_SITE_GNOME:=sources/atk/1.0/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://developer.gnome.org/projects/gap/
COMMENT=		Set of interfaces for accessibility

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/atk.pc.in

# glib-mkenums overflows a 2048kb stack on atkobject.h 
UNLIMIT_RESOURCES=	stacksize

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
