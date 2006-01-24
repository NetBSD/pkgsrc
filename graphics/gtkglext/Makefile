# $NetBSD: Makefile,v 1.29 2006/01/24 07:32:15 wiz Exp $

DISTNAME=	gtkglext-1.0.6
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkglext/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gtkglext.sourceforge.net/
COMMENT=	OpenGL extension to GTK

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl pkg-config
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	gdkglext.pc.in
PKGCONFIG_OVERRIDE+=	gtkglext.pc.in
LIBS+=			-lm

CONFIGURE_ARGS+=        --with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=        --enable-gtk-doc=no

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
