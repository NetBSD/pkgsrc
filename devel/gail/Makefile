# $NetBSD: Makefile,v 1.15 2004/01/23 21:50:43 jmmv Exp $
#

DISTNAME=	gail-1.4.1
PKGREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gail/1.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://developer.gnome.org/projects/gap/
COMMENT=	GNOME Accessibility Implementation Library

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
USE_LIBTOOL=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	gail.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

.include "../../devel/atk/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
