# $NetBSD: Makefile,v 1.8 2002/09/11 11:31:40 jlam Exp $
#

DISTNAME=		glib-2.0.6
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
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PERL5=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/glib
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

# GLib needs a working pre-emptive pthreads implementation
PTHREAD_OPTS+=		native

test: build
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE_PROGRAM} check 2>&1 | \
		tee ${WRKDIR}/check.log

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CPPFLAGS+=		-I${BUILDLINK_PREFIX.ptl2}/PTL/include
.  include "../../devel/ptl2/buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
