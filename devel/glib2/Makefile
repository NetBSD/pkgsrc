# $NetBSD: Makefile,v 1.4 2002/06/30 16:26:45 dmcmahill Exp $
#

DISTNAME=		glib-2.0.4
PKGNAME=		${DISTNAME:S/glib/glib2/}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.0/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.0/ \
			http://www.ameth.org/gimp/pub/gtk/v2.0/ \
			${MASTER_SITE_GNOME:=stable/sources/glib/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gtk.org/docs/glib_toc.html
COMMENT=		Some useful routines for C programming

BUILD_USES_MSGFMT=	yes
GNU_CONFIGURE=		yes
USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_PERL5=		yes
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/glib
CPPFLAGS+=		-I${BUILDLINK_DIR}/PTL/include
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

# GLib needs a working pre-emptive pthreads implementation
USE_PTHREAD=	native ptl2

test: build
	cd ${WRKSRC} &&  ${MAKE_ENV} ${MAKE_PROGRAM} check 2>&1 | \
		tee ${WRKDIR}/check.log

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/pkgconfig/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
