# $NetBSD: Makefile,v 1.29.2.2 2002/06/21 23:05:22 jlam Exp $
#

DISTNAME=	gqview-1.0.1
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	another gtk-based graphic file viewer

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_path_GNOME_CONFIG=no
CONFIGURE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"

BUILDLINK_DEPENDS.gdk-pixbuf=	gdk-pixbuf>=0.11.0nb1

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
