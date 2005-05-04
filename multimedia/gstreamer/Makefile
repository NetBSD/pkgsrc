# $NetBSD: Makefile,v 1.24 2005/05/04 16:27:08 drochner Exp $
#

DISTNAME=		gstreamer-0.8.10
CATEGORIES=		multimedia gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gstreamer/0.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gstreamer.net/
COMMENT=		GNOME multimedia streamer library

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=		yes
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
CONFIGURE_ARGS+=	HAVE_GTK_DOC=no

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-control.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer.pc.in

MAKE_DIRS+=		${GST_DBDIR}

PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# We must have a glib2 compiled with the RTLD_GLOBAL fix; if not, plugins
# won't work at all.
BUILDLINK_DEPENDS.glib2+=	glib2>=2.4.0nb1
.endif
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
