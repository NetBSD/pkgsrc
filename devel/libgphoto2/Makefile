# $NetBSD: Makefile,v 1.8 2003/08/05 09:19:25 adam Exp $
#

DISTNAME=	libgphoto2-2.1.1
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/libgphoto2/
COMMENT=	Digital camera access library

CONFLICTS+=	gphoto<2.1.1

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libgphoto2_port/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgphoto2/libgphoto2.pc.in
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libusb/buildlink2.mk"
.include "../../graphics/libexif/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
