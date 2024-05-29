# $NetBSD: Makefile,v 1.84 2024/05/29 16:32:13 adam Exp $

DISTNAME=	libgphoto2-2.5.27
PKGREVISION=	7
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
# Build very old camera libraries (outdated set)
CONFIGURE_ARGS+=	--with-camlibs=standard,outdated
PKGCONFIG_OVERRIDE+=	libgphoto2.pc.in libgphoto2_port/libgphoto2_port.pc.in

REPLACE_SH=		packaging/generic/check-ptp-camera

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	libusb

BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,--version-script=./libgphoto2_port.ver:-Wl,-M./libgphoto2_port.ver
CONFIGURE_ARGS.SunOS+=		--without-libusb

SUBST_CLASSES.SunOS+=	mapfile
SUBST_STAGE.mapfile=	pre-configure
SUBST_FILES.mapfile=	libgphoto2_port/libgphoto2_port/libgphoto2_port.ver
SUBST_SED.mapfile=	-e '/gpi_gphoto_port_type_map/d'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.if ${OPSYS} != "SunOS"
PLIST.libusb=	yes
.include "../../devel/libusb1/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
