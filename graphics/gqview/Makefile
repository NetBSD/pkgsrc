# $NetBSD: Makefile,v 1.25 2001/10/24 22:11:01 jlam Exp $
#

DISTNAME=	gqview-0.12.0
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	another gtk-based graphic file viewer

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK_ONLY=	yes

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_path_GNOME_CONFIG=no
CONFIGURE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"

BUILDLINK_DEPENDS.gdk-pixbuf=	gdk-pixbuf>=0.9.0

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
