# $NetBSD: Makefile,v 1.10 2002/09/11 11:44:35 jlam Exp $
#

DISTNAME=		pango-1.0.4
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.0/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.0/ \
			http://www.ameth.org/gimp/pub/gtk/v2.0/ \
			${MASTER_SITE_GNOME:=stable/sources/pango/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.pango.org
COMMENT=		Library for layout and rendering of text

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

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

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
