# $NetBSD: Makefile,v 1.27 2006/02/05 23:08:45 joerg Exp $
#

DISTNAME=	libgphoto2-2.1.6
PKGREVISION=	1
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/libgphoto2/
COMMENT=	Digital camera access library

CONFLICTS+=	gphoto<2.1.1

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	libgphoto2/libgphoto2.pc.in
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

SUBST_CLASSES+=		libexif-update
SUBST_STAGE.libexif-update=	pre-configure
SUBST_MESSAGE.libexif-update=	Fix configure script checks for libexif-0.6.13
SUBST_FILES.libexif-update=	configure
SUBST_SED.libexif-update=	s,exif-,libexif/exif-,g

.include "../../mk/bsd.prefs.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.if ${OPSYS} == "SunOS"
PLIST_SUBST+=		HAVE_LIBUSB="@comment"
.else
.include "../../devel/libusb/buildlink3.mk"
PLIST_SUBST+=		HAVE_LIBUSB=""
.endif
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
