# $NetBSD: Makefile,v 1.8 2002/12/24 21:38:33 wiz Exp $
#

DISTNAME=	gtkam-0.1.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/gphoto2/
COMMENT=	digital camera access graphical client (GTK2)

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../devel/libgphoto2/buildlink2.mk"
.include "../../graphics/libexif-gtk/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
