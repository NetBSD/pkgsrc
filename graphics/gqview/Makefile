# $NetBSD: Makefile,v 1.33 2002/11/30 14:50:13 grant Exp $
#

DISTNAME=	gqview-1.0.1
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	another gtk-based graphic file viewer

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK2=		# defined
USE_X11BASE=		# defined
GNU_CONFIGURE=		# defined
USE_PKGLOCALEDIR=	# defined
CONFIGURE_ENV+=		ac_cv_path_GNOME_CONFIG=no

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
