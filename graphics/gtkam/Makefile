# $NetBSD: Makefile,v 1.21 2004/04/13 16:27:26 reed Exp $
#

DISTNAME=	gtkam-0.1.11
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/gphoto2/
COMMENT=	Digital camera access graphical client (GTK2)

DEPENDS+=		gnome2-dirs>=1.5:../../misc/gnome2-dirs

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-bonobo
CONFIGURE_ARGS+=	--without-bonobo-activation
CONFIGURE_ARGS+=	--without-gnome

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/libexif-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
