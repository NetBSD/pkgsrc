# $NetBSD: Makefile,v 1.12 2004/04/27 03:09:58 snj Exp $
#

DISTNAME=		gscope-0.4.1
PKGREVISION=		5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gscope/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gscope.sourceforge.net/
COMMENT=		Software oscilloscope library

BUILD_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc

USE_BUILDLINK3=		yes
USE_X11=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
