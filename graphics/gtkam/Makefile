# $NetBSD: Makefile,v 1.10 2003/05/02 11:55:21 wiz Exp $
#

DISTNAME=	gtkam-0.1.10
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/gphoto2/
COMMENT=	digital camera access graphical client (GTK2)

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-bonobo
CONFIGURE_ARGS+=	--without-bonobo-activation

.include "../../devel/libgphoto2/buildlink2.mk"
.include "../../graphics/libexif-gtk/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
