# $NetBSD: Makefile,v 1.11 2004/01/03 18:49:43 reed Exp $

DISTNAME=	libexif-gtk-0.3.3
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libexif/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://libexif.sourceforge.net/
COMMENT=	EXIF file library (GTK2 interface)

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	libexif-gtk/libexif-gtk.pc.in

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/libexif/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
