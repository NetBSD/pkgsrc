# $NetBSD: Makefile,v 1.13 2002/07/16 08:49:30 agc Exp $
#

DISTNAME=	gdcd-0.2.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://cdcd.undergrid.net/gdcd/source_archive/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://cdcd.undergrid.net/
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
