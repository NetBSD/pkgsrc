# $NetBSD: Makefile,v 1.19 2001/06/18 21:48:52 jlam Exp $
#

DISTNAME=	gqview-0.10.1
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	another gtk-based graphic file viewer

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK_ONLY=	yes
USE_CONFIG_WRAPPER=	yes

#USE_LIBINTL=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_path_GNOME_CONFIG=no
CONFIGURE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"

GDK_PIXBUF_REQD=	0.9.0

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
