# $NetBSD: Makefile,v 1.1.1.1 2002/06/19 13:00:41 agc Exp $
#

DISTNAME=		gscope-0.4.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gscope/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://gscope.sourceforge.net/
COMMENT=		software oscilloscope library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

BUILD_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc

.include "../../devel/popt/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
