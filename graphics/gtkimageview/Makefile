# $NetBSD: Makefile,v 1.2 2008/08/31 23:22:21 gdt Exp $

DISTNAME=	gtkimageview-1.6.1
CATEGORIES=	graphics
# See ticket:27 on trac, and until then, download by hand.
MASTER_SITES=	http://trac.bjourne.webfactional.com/attachment/wiki/WikiStart/broken

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac.bjourne.webfactional.com/
COMMENT=	Image viewer widget for GTK

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	gtkimageview-1.0.pc.in

.include "../../devel/glib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
