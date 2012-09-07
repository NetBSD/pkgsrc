# $NetBSD: Makefile,v 1.19 2012/09/07 19:16:47 adam Exp $

DISTNAME=	gtkimageview-1.6.4
PKGREVISION=	10
CATEGORIES=	graphics
MASTER_SITES= 	http://trac.bjourne.webfactional.com/chrome/common/releases/

# This package has no NEWS, and it is very difficult to find the
# summary of changes.  See
# http://trac.bjourne.webfactional.com/ticket/28 in which the author
# points to the following URL for the content that would normally be
# in NEWS:
# http://trac.bjourne.webfactional.com/chrome/common/gtkimageview-docs/releasehistory.html
MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac.bjourne.webfactional.com/
COMMENT=	Image viewer widget for GTK

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	gtkimageview-1.0.pc.in

TEST_TARGET=	check

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
