# $NetBSD: Makefile,v 1.7 2003/02/14 20:21:57 jmmv Exp $
#

DISTNAME=	gail-1.2.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gail/1.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://developer.gnome.org/projects/gap/
COMMENT=	GNOME Accessibility Implementation Library

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_X11=		yes
USE_LIBTOOL=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/gail.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

.include "../../devel/atk/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
