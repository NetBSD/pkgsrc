# $NetBSD: Makefile,v 1.20 2004/10/03 00:14:52 tv Exp $

DISTNAME=		gtkglext-0.7.1
PKGREVISION=		6
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkglext/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gtkglext.sourceforge.net/
COMMENT=		OpenGL extension to GTK

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PERL5=		build
USE_X11=		YES

PKGCONFIG_OVERRIDE=	gdkglext.pc.in
PKGCONFIG_OVERRIDE+=	gtkglext.pc.in
LIBS+=			-lm

CONFIGURE_ARGS+=        --with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=        --enable-gtk-doc=no

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
