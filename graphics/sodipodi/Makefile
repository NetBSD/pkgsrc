# $NetBSD: Makefile,v 1.5 2002/07/12 22:51:27 mycroft Exp $
#

DISTNAME=	sodipodi-0.23
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sodipodi/}

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://www.gnome.org/gnome-office/sodipodi.shtml
COMMENT=	Open source vector graphics drawing program using SVG as native format

GNU_CONFIGURE=		YES
# -I/usr/pkg/include is added to CFLAGS somehow
#USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

PTHREAD_TYPE=	native pth

.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../net/ORBit/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
