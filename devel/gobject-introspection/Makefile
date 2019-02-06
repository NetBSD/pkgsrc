# $NetBSD: Makefile,v 1.57 2019/02/06 11:29:35 martin Exp $

DISTNAME=	gobject-introspection-1.56.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gobject-introspection/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/GObjectIntrospection
COMMENT=	GObject Introspection
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config flex bison gmake
GMAKE_REQD=	3.81
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-doctool

PKGCONFIG_OVERRIDE+=	gobject-introspection-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gobject-introspection-no-export-1.0.pc.in

SUBST_CLASSES+=		timet
SUBST_STAGE.timet=	pre-configure
SUBST_FILES.timet=	giscanner/ast.py
SUBST_FILES.timet+=	tests/scanner/Regress-1.0-expected.gir
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-5.99*) || !empty(MACHINE_PLATFORM:MNetBSD-[6-9]*) || !empty(MACHINE_PLATFORM:MMirBSD-*)
SUBST_SED.timet=	-e 's,@TIMET_TYPENAME@,TYPE_INT64,g'
SUBST_SED.timet+=	-e 's,@TIMET_CTYPE@,gint64,g'
.else
SUBST_SED.timet=	-e 's,@TIMET_TYPENAME@,TYPE_LONG,g'
SUBST_SED.timet+=	-e 's,@TIMET_CTYPE@,glong,g'
.endif

#REPLACE_PYTHON+=	tools/g-ir-tool-template.in
SUBST_CLASSES+=		pyenv
SUBST_STAGE.pyenv=	pre-configure
SUBST_FILES.pyenv+=	tools/g-ir-tool-template.in
SUBST_SED.pyenv+=	-e 's,/usr/bin/env ,,'

# not executable
CHECK_INTERPRETER_SKIP+= lib/gobject-introspection/giscanner/*.py

# needed for tests only
#.include "../../graphics/cairo/buildlink3.mk"
#.include "../../graphics/cairo-gobject/buildlink3.mk"
#TEST_TARGET=	check

BUILDLINK_API_DEPENDS.glib2+= glib2>=2.54.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libffi+= libffi>=3.0.0
.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
