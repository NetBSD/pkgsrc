# $NetBSD: Makefile,v 1.5 2002/11/30 23:21:37 salo Exp $
#

DISTNAME=	libbonoboui-2.0.3.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libbonoboui/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 Object activation framework library (graphical version)

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
USE_GNU_GETTEXT=	yes
USE_X11=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
