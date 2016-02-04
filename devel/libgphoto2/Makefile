# $NetBSD: Makefile,v 1.65 2016/02/04 11:57:50 wiz Exp $

DISTNAME=	libgphoto2-2.5.8
PKGREVISION=	1
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/
COMMENT=	Digital camera access library
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	gphoto<2.1.1

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_DOXYGEN=false
CONFIGURE_ARGS+=	--with-gdlib=no
PKGCONFIG_OVERRIDE+=	libgphoto2.pc.in libgphoto2_port/libgphoto2_port.pc.in

REPLACE_SH=		packaging/generic/check-ptp-camera

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	libusb

.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	opt:-Wl,--version-script=./libgphoto2_port.ver:-Wl,-M./libgphoto2_port.ver

SUBST_CLASSES+=	mapfile
SUBST_STAGE.mapfile=	post-patch
SUBST_FILES.mapfile=	libgphoto2_port/libgphoto2_port/libgphoto2_port.ver
SUBST_SED.mapfile=	-e '/gpi_gphoto_port_type_map/d'
.endif

# remove symbolic link
post-install:
	rm ${DESTDIR}${PREFIX}/include/gphoto2/gphoto2

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.if ${OPSYS} != "SunOS"
PLIST.libusb=	yes
.include "../../devel/libusb/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
