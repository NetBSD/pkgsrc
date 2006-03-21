# $NetBSD: Makefile,v 1.31 2006/03/21 06:00:46 jlam Exp $
#

DISTNAME=	gtkam-0.1.12
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/gphoto2/
COMMENT=	Digital camera access graphical client (GTK2)

USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-bonobo
CONFIGURE_ARGS+=	--without-bonobo-activation
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--without-gimp

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/libexif-gtk/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
