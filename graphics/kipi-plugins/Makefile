# $NetBSD: Makefile,v 1.49 2010/02/15 14:40:38 wiz Exp $
#

DISTNAME=	kipi-plugins-1.1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kipi/kipi-plugins/1.1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kipi-plugins.org/drupal/
COMMENT=	Common plugin structure for KDE4 programs
#LICENSE=	gnu-gpl-v2 AND Adobe DNG SDK license

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt pkg-config

# for IpodExport
.include "../../audio/libgpod/buildlink3.mk"
.include "../../graphics/kdegraphics4/buildlink3.mk"
# for RemoveRedEyes
.include "../../graphics/opencv/buildlink3.mk"
# for Calendar
.include "../../misc/kdepimlibs4/buildlink3.mk"
# for Shwup
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/expat/buildlink3.mk"
# for Gdk for IpodExport XXX: configure doesn't accept it.
#.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
