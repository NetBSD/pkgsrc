# $NetBSD: Makefile,v 1.7 2003/06/02 01:19:25 jschauma Exp $
#

<<<<<<< Makefile
DISTNAME=		gtkglext-0.6.1
PKGREVISION=		1
=======
DISTNAME=		gtkglext-0.7.1
<<<<<<< Makefile
>>>>>>> 1.5
=======
PKGREVISION=		1
>>>>>>> 1.6
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkglext/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://gtkglext.sourceforge.net/
COMMENT=		OpenGL extension to GTK

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PERL5=		build
USE_GMAKE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/gtkglext.pc.in
LIBS+=			-lm

CONFIGURE_ARGS+=        --with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=        --enable-gtk-doc=no

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
