# $NetBSD: Makefile,v 1.16 2004/10/03 00:13:02 tv Exp $
#

DISTNAME=		gstreamer-0.8.5
PKGREVISION=		1
CATEGORIES=		multimedia gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gstreamer/0.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gstreamer.net/
COMMENT=		GNOME multimedia streamer library

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		build

CONFIGURE_ARGS+=	--disable-plugin-builddir
CONFIGURE_ARGS+=	--localstatedir=${PREFIX}/libdata/gstreamer-0.8
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV+=		ac_cv_path_PYTHON="${PYTHONBIN}"

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-control.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer.pc.in

PYTHON_VERSIONS_ACCEPTED=	23 23pth 22 22pth

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# We must have a glib2 compiled with the RTLD_GLOBAL fix; if not, plugins
# won't work at all.
BUILDLINK_DEPENDS.glib2+=	glib2>=2.4.0nb1
.endif

# XXX: Set up compatibility links for gstreamer-0.8.3; this is just a
# workaround for our broken libtool naming, and it should be removed when
# our libtool is fixed.
post-install:
.for f in gstcontrol gstreamer
	cd ${PREFIX}/lib && ${LN} -fs lib${f}-0.8.so.5 lib${f}-0.8.so.3
	cd ${PREFIX}/lib && ${LN} -fs lib${f}-0.8.so.5.0 lib${f}-0.8.so.3.0
.endfor
.undef f

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../lang/python/application.mk"
_GSTREAMER_NO_DEPEND=		# defined
.include "../../multimedia/gstreamer/plugins.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
