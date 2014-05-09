# $NetBSD: Makefile,v 1.40 2014/05/09 07:36:59 wiz Exp $

DISTNAME=	gobject-introspection-1.38.0
PKGREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gobject-introspection/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/GObjectIntrospection
COMMENT=	GObject Introspection
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.38.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config flex bison gmake
GMAKE_REQD=	3.81

PKGCONFIG_OVERRIDE+=	gobject-introspection-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gobject-introspection-no-export-1.0.pc.in

SUBST_CLASSES+=	timet
SUBST_STAGE.timet=	pre-configure
SUBST_FILES.timet=	giscanner/ast.py
SUBST_FILES.timet+=	tests/scanner/Regress-1.0-expected.gir
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-5.99*) || !empty(MACHINE_PLATFORM:MNetBSD-[6-9]*) || !empty(MACHINE_PLATFORM:MMirBSD)
SUBST_SED.timet=	-e 's,@TIMET_TYPENAME@,TYPE_INT64,g'
SUBST_SED.timet+=	-e 's,@TIMET_CTYPE@,gint64,g'
.else
SUBST_SED.timet=	-e 's,@TIMET_TYPENAME@,TYPE_LONG,g'
SUBST_SED.timet+=	-e 's,@TIMET_CTYPE@,glong,g'
.endif

# not executable
CHECK_INTERPRETER_SKIP+= lib/gobject-introspection/giscanner/*.py

PKGCONFIG_OVERRIDE+=	gobject-introspection-1.0.pc.in

CONFIGURE_ARGS+=	--disable-doctool --disable-tests
# needed for tests only
#.include "../../graphics/cairo/buildlink3.mk"
#.include "../../graphics/cairo-gobject/buildlink3.mk"
#TEST_TARGET=	check

BUILDLINK_API_DEPENDS.glib2+= glib2>=2.36.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libffi+= libffi>=3.0.0
.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
