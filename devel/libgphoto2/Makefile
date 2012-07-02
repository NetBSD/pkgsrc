# $NetBSD: Makefile,v 1.57 2012/07/02 16:08:29 drochner Exp $

DISTNAME=	libgphoto2-2.4.14
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/libgphoto2/
COMMENT=	Digital camera access library
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	gphoto<2.1.1

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_DOXYGEN=false
PKGCONFIG_OVERRIDE+=	libgphoto2.pc.in libgphoto2_port/libgphoto2_port.pc.in

.include "../../mk/bsd.prefs.mk"

# remove symbolic link
post-install:
	rm ${DESTDIR}${PREFIX}/include/gphoto2/gphoto2

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
