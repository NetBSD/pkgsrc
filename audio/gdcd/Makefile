# $NetBSD: Makefile,v 1.26 2004/04/25 04:16:42 xtraeme Exp $
#

DISTNAME=	gdcd-0.2.1
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://gdcd.undergrid.net/source_archive/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gdcd.undergrid.net/
COMMENT=	CD player for the X Window System using the GIMP Tool Kit (GTK)

USE_DIRS+=	xdg-1.1
USE_X11=	YES
GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES

.include "../../audio/libcdaudio/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
