# $NetBSD: Makefile,v 1.1.1.1 2008/08/31 00:09:13 gdt Exp $

DISTNAME=	gtkimageview-1.3.0
CATEGORIES=	graphics
MASTER_SITES=	http://trac.bjourne.webfactional.com/attachment/wiki/WikiStart/gtkimageview-1.3.0.tar.gz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac.bjourne.webfactional.com/wiki
COMMENT=	Image viewer widget for GTK

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	gtkimageview-1.0.pc.in

.include "../../devel/glib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
