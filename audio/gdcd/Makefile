# $NetBSD: Makefile,v 1.21 2004/01/03 18:49:33 reed Exp $
#

DISTNAME=	gdcd-0.2.1
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://gdcd.undergrid.net/source_archive/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gdcd.undergrid.net/
COMMENT=	CD player for the X Window System using the GIMP Tool Kit (GTK)

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

.include "../../audio/libcdaudio/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
