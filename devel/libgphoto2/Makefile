# $NetBSD: Makefile,v 1.10 2004/02/14 17:21:38 jlam Exp $
#

DISTNAME=	libgphoto2-2.1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/libgphoto2/
COMMENT=	Digital camera access library

CONFLICTS+=	gphoto<2.1.1

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgphoto2/libgphoto2.pc.in
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libusb/buildlink2.mk"
.include "../../graphics/libexif/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
