# $NetBSD: Makefile,v 1.11 2004/04/25 04:16:43 xtraeme Exp $
#

DISTNAME=		gscope-0.4.1
PKGREVISION=		5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gscope/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gscope.sourceforge.net/
COMMENT=		Software oscilloscope library

BUILD_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc

USE_BUILDLINK2=		# defined
USE_X11=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

.include "../../devel/popt/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
