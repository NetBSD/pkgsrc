# $NetBSD: Makefile,v 1.31 2004/10/12 18:39:44 jmmv Exp $
#

DISTNAME=		gcalctool-4.4.20
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gcalctool/4.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://calctool.sourceforge.net/
COMMENT=		Desktop calculator for GNOME

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		gcalctool.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
