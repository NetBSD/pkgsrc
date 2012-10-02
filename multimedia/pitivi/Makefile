# $NetBSD: Makefile,v 1.18 2012/10/02 17:11:42 tron Exp $
#

DISTNAME=	pitivi-0.15.0
PKGREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pitivi/0.15/}
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pitivi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pitivi.org/
COMMENT=	Video editor

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt
PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ENV+=	ac_cv_path_PYTHON=${PYTHONBIN}
PYTHON_PATCH_SCRIPTS=	bin/pitivi.in
# no 25, needs setter/getter
PYTHON_VERSIONS_ACCEPTED= 27 26

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-gnonlin/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
