# $NetBSD: Makefile,v 1.4 2002/06/30 01:51:29 jschauma Exp $
#

DISTNAME=		pango-1.0.3
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.0/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.0/ \
			http://www.ameth.org/gimp/pub/gtk/v2.0/ \
			${MASTER_SITE_GNOME:=stable/sources/pango/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.pango.org
COMMENT=		Library for layout and rendering of text

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_GMAKE=		yes

test: build
	cd ${WRKSRC} &&  ${MAKE_ENV} ${MAKE_PROGRAM} check 2>&1 | \
		tee ${WRKDIR}/check.log

.include "../../devel/glib2/buildlink.mk"
.include "../../devel/pkgconfig/buildlink.mk"
.include "../../graphics/freetype2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
