# $NetBSD: Makefile,v 1.5 2002/07/03 01:29:39 dmcmahill Exp $
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

# directory appeared in XFree86 4.*
# if it is there, we are using XFree86 4.* and will
# install some additional files
.if exists(${X11BASE}/lib/X11/locale/common)
PLIST_SRC=		${PKGDIR}/PLIST.xf4 ${PKGDIR}/PLIST
.else
PLIST_SRC=		${PKGDIR}/PLIST
.endif

test: build
	cd ${WRKSRC} &&  ${MAKE_ENV} ${MAKE_PROGRAM} check 2>&1 | \
		tee ${WRKDIR}/check.log

.include "../../devel/glib2/buildlink.mk"
.include "../../devel/pkgconfig/buildlink.mk"
.include "../../graphics/freetype2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
