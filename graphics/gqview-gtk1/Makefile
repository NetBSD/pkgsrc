# $NetBSD: Makefile,v 1.1.1.1 2004/07/05 18:20:00 wiz Exp $

DISTNAME=	gqview-1.2.2
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	GTK1-based graphic file viewer

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined
USE_DIRS+=		xdg-1.1 gnome1-1.5
USE_PKGLOCALEDIR=	# defined

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
