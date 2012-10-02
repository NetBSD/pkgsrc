# $NetBSD: Makefile,v 1.49 2012/10/02 17:11:13 tron Exp $

DISTNAME=	gtkglext-1.2.0
PKGREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkglext/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtkglext.sourceforge.net/
COMMENT=	OpenGL extension to GTK
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk-doc=no

PKGCONFIG_OVERRIDE=	gdkglext.pc.in
PKGCONFIG_OVERRIDE+=	gtkglext.pc.in
LIBS+=			-lm

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.20.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
