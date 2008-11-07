# $NetBSD: Makefile,v 1.36 2008/11/07 20:11:30 sborrill Exp $
#

DISTNAME=	gtkam-0.1.16
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/gtkam/
COMMENT=	Digital camera access graphical client (GTK2)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		pkg-config perl
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-bonobo
CONFIGURE_ARGS+=	--without-bonobo-activation
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--without-gimp

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/libexif-gtk/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
