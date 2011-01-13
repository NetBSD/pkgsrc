# $NetBSD: Makefile,v 1.6 2011/01/13 13:38:57 wiz Exp $
#

DISTNAME=	pitivi-0.13.4
PKGREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pitivi/0.13/}
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pitivi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pitivi.org/
COMMENT=	Video editor

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config intltool gmake
PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ENV+=	ac_cv_path_PYTHON=${PYTHONBIN}
PYTHON_PATCH_SCRIPTS=	bin/pitivi.in
PYTHON_VERSIONS_ACCEPTED= 26 25

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-gnonlin/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
