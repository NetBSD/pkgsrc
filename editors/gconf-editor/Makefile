# $NetBSD: Makefile,v 1.17 2004/04/01 18:51:26 jmmv Exp $
#

DISTNAME=		gconf-editor-2.6.0
CATEGORIES=		editors gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gconf-editor/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Editor for the GConf configuration system

BUILD_USES_MSGFMT=	YES
DEPENDS+=		xdg-dirs>=1.1:../../misc/xdg-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11=		YES

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
