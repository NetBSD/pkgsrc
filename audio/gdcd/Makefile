# $NetBSD: Makefile,v 1.14 2002/08/31 02:55:48 wiz Exp $
#

DISTNAME=	gdcd-0.2.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://gdcd.undergrid.net/source_archive/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://gdcd.undergrid.net/
COMMENT=	CD player for the X Window System using the GIMP Tool Kit (GTK)

USE_X11BASE=	YES
GNU_CONFIGURE=	YES

USE_BUILDLINK_ONLY=	yes

.include "../../audio/libcdaudio/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
