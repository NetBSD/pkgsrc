# $NetBSD: Makefile,v 1.13 2002/11/30 14:28:07 grant Exp $
#

DISTNAME=		glib-2.0.7
PKGNAME=		${DISTNAME:S/glib/glib2/}
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.0/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.0/ \
			http://www.ameth.org/gimp/pub/gtk/v2.0/ \
			${MASTER_SITE_GNOME:=sources/glib/2.0/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gtk.org/docs/glib_toc.html
COMMENT=		Some useful routines for C programming

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PERL5=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gmodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gobject-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gthread-2.0.pc.in

GNU_CONFIGURE=		# defined
USE_PKGLOCALEDIR=	# defined
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/glib

.include "../../mk/bsd.prefs.mk"

.if defined(USE_PTL2)
PTHREAD_OPTS+=		native
.endif

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
