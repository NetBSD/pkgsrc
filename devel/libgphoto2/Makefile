# $NetBSD: Makefile,v 1.20 2005/01/05 15:52:52 drochner Exp $
#

DISTNAME=	libgphoto2-2.1.5
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/libgphoto2/
COMMENT=	Digital camera access library

CONFLICTS+=	gphoto<2.1.1

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	libgphoto2/libgphoto2.pc.in
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
