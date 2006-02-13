# $NetBSD: Makefile,v 1.31 2006/02/13 20:56:15 adam Exp $

DISTNAME=	gtkglext-1.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkglext/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gtkglext.sourceforge.net/
COMMENT=	OpenGL extension to GTK

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

PKGCONFIG_OVERRIDE=	gdkglext.pc.in
PKGCONFIG_OVERRIDE+=	gtkglext.pc.in
LIBS+=			-lm

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
