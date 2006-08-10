# $NetBSD: Makefile,v 1.34 2006/08/10 17:44:11 drochner Exp $

DISTNAME=	gtkglext-1.2.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkglext/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtkglext.sourceforge.net/
COMMENT=	OpenGL extension to GTK

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk-doc=no

PKGCONFIG_OVERRIDE=	gdkglext.pc.in
PKGCONFIG_OVERRIDE+=	gtkglext.pc.in
LIBS+=			-lm

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
