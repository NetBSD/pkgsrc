# $NetBSD: Makefile,v 1.3 2008/09/01 13:29:53 gdt Exp $

DISTNAME=	gtkimageview-1.6.1
PKGREVISION=	1
CATEGORIES=	graphics
# See http://trac.bjourne.webfactional.com/ticket/27
# MASTER_SITES=	http://trac.bjourne.webfactional.com/attachment/wiki/WikiStart/broken
MASTER_SITES=	http://www.lexort.com/pkgsrc/distfiles/

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
