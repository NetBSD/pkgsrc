# $NetBSD: Makefile,v 1.8 2002/09/12 00:43:49 wiz Exp $
#

DISTNAME=	sodipodi-0.25
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sodipodi/}

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://www.gnome.org/gnome-office/sodipodi.shtml
COMMENT=	Open source vector graphics drawing program using SVG as native format

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

PTHREAD_OPTS+=		require

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../net/ORBit/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
