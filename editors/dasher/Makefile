# $NetBSD: Makefile,v 1.1.1.1 2004/02/23 19:01:53 jmmv Exp $
#

DISTNAME=	dasher-3.2.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dasher/3.2/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.inference.phy.cam.ac.uk/dasher/
COMMENT=	Easy typing without using keyboard

DEPENDS+=		xdg-dirs>=1.0:../../misc/xdg-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
