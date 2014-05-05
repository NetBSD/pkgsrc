# $NetBSD: Makefile,v 1.31 2014/05/05 00:47:58 ryoon Exp $

DISTNAME=	gtkimageview-1.6.4
PKGREVISION=	20
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

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	gtkimageview-1.0.pc.in

TEST_TARGET=	check

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=unused-function
.endif

.include "../../mk/bsd.pkg.mk"
