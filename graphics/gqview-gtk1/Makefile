# $NetBSD: Makefile,v 1.7 2006/04/13 18:23:33 jlam Exp $

DISTNAME=	gqview-1.2.2
PKGREVISION=	3
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	GTK1-based graphic file viewer

GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt
USE_DIRS+=		xdg-1.1 gnome1-1.5
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
