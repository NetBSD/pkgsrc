# $NetBSD: Makefile,v 1.49 2011/11/01 06:01:36 sbd Exp $
#

DISTNAME=	gtkam-0.1.16
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/gtkam/
COMMENT=	Digital camera access graphical client (GTK2)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		intltool pkg-config perl msgfmt
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-bonobo
CONFIGURE_ARGS+=	--without-bonobo-activation
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--without-gimp

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/libexif-gtk/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
