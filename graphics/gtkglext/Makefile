# $NetBSD: Makefile,v 1.4 2003/01/14 05:35:53 rh Exp $
#

DISTNAME=		gtkglext-0.6.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkglext/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
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

.include "../../textproc/gtk-doc/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
