# $NetBSD: Makefile,v 1.40 2008/04/29 09:31:38 sborrill Exp $

DISTNAME=	libgphoto2-2.4.1
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/libgphoto2/
COMMENT=	Digital camera access library

CONFLICTS+=	gphoto<2.1.1

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_DOXYGEN=false
PKGCONFIG_OVERRIDE+=	libgphoto2/libgphoto2.pc.in
PLIST_VARS+=		libusb

.include "../../mk/bsd.prefs.mk"
# Keep this in sync with libusb/buildlink3.mk!
.if ${OPSYS} != "SunOS"
.  include "../../devel/libusb/buildlink3.mk"
PLIST.libusb=		yes
.endif

# remove symbolic link
post-install:
	rm ${PREFIX}/include/gphoto2/gphoto2

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
