# $NetBSD: Makefile,v 1.3 2004/12/04 11:54:25 wiz Exp $
#

DISTNAME=	gtranslator-1.0
PKGREVISION=	10
CATEGORIES=	editors
MASTER_SITES=	http://gtranslator.sourceforge.net/download/releases/1.0/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gtranslator.sourceforge.net/
COMMENT=	Gettext po file editor for the GNOME2 desktop environment

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
MANCOMPRESSED=		yes

CONFIGURE_ARGS+=	--disable-debug

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
