# $NetBSD: Makefile,v 1.28 2005/02/26 17:24:35 jmmv Exp $
#

DISTNAME=	gail-1.8.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gail/1.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://developer.gnome.org/projects/gap/
COMMENT=	GNOME Accessibility Implementation Library

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE=	gail.pc.in
PKGCONFIG_OVERRIDE+=	gail-uninstalled.pc.in

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
