# $NetBSD: Makefile,v 1.44 2021/05/24 19:53:12 wiz Exp $
#

.include "Makefile.common"
PKGREVISION=		18

#CONFIGURE_ARGS+=	--disable-silent-rules

COMMENT+=		Base plugins

# some plugins were moved from bad to base
CONFLICTS+=		gst-plugins0.10-bad<0.10.10

USE_TOOLS+=		perl:run autoconf automake gmake
USE_TOOLS+=		autoreconf autopoint
TOOL_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc

MAKE_JOBS_SAFE=		no
PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in
REPLACE_PERL+=		tools/gst-visualise-m.m

PKG_OPTIONS_VAR=	PKG_OPTIONS.gst-plugins0.10-base
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=	introspection
.include "../../mk/bsd.options.mk"

PLIST_VARS+=	introspection

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

# soft dependency only, .pc file not needed
#.include "../../textproc/iso-codes/buildlink3.mk"

.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=	yes
.include "../../devel/gobject-introspection/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-introspection
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

# XXX: hack
# autoreconf some breaks the file names of the .mo files
# manually fix this here instead of debugging generated Makefiles
post-install:
	find ${DESTDIR}${PREFIX}/share/locale -name .mo -execdir mv .mo gst-plugins-base-0.10.mo \;

.include "../../mk/bsd.pkg.mk"
