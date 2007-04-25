# $NetBSD: Makefile,v 1.37 2007/04/25 13:36:18 sborrill Exp $

DISTNAME=	libgphoto2-2.3.1
PKGREVISION=	3
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
CONFIGURE_FLAGS+=	DOXYGEN=no
PKGCONFIG_OVERRIDE+=	libgphoto2/libgphoto2.pc.in

.include "../../mk/bsd.prefs.mk"
# Keep this in sync with buildlink3.mk!
.if ${OPSYS} == "SunOS"
PLIST_SUBST+=		HAVE_LIBUSB="@comment "
.else
.include "../../devel/libusb/buildlink3.mk"
PLIST_SUBST+=		HAVE_LIBUSB=""
.endif

# remove symbolic link
post-install:
	rm ${PREFIX}/include/gphoto2/gphoto2

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
