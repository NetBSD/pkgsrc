# $NetBSD: Makefile,v 1.7 2009/02/16 16:25:38 drochner Exp $

DISTNAME=	gtkimageview-1.6.3
PKGREVISION=	1
CATEGORIES=	graphics
# See http://trac.bjourne.webfactional.com/ticket/27
# MASTER_SITES=	http://trac.bjourne.webfactional.com/attachment/wiki/WikiStart/broken
MASTER_SITES=	http://www.lexort.com/pkgsrc/distfiles/
# This package has no NEWS, and it is very difficult to find the summary of changes.
# See http://trac.bjourne.webfactional.com/ticket/28 in which the author points
# to the following URL for the content that would normally be in NEWS:
# http://trac.bjourne.webfactional.com/chrome/common/gtkimageview-docs/releasehistory.html

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac.bjourne.webfactional.com/
COMMENT=	Image viewer widget for GTK

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	gtkimageview-1.0.pc.in

TEST_TARGET=	check

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
