# $NetBSD: Makefile,v 1.30 2023/10/23 06:37:38 wiz Exp $

.include "../../devel/glib2/Makefile.common"

PKGNAME:=	${PKGNAME:S/glib2/gdbus-codegen/}
CATEGORIES=	devel gnome

COMMENT=	Generate code and/or documentation for one or more D-Bus interfaces

WRKSRC=		${WRKDIR}/${DISTNAME}/gio/gdbus-2.0/codegen

SUBST_CLASSES+=		autovars
SUBST_STAGE.autovars=	pre-configure
SUBST_MESSAGE.autovars=	autoconf meson.build
SUBST_FILES.autovars=	meson.build config.py.in gdbus-codegen.in
SUBST_VARS.autovars=	PKGVERSION PYTHONBIN
SUBST_SED.autovars=	-e 's,@VERSION@,${PKGVERSION:Q},'
SUBST_SED.autovars+=	-e 's,@MAJOR_VERSION@,${PKGVERSION:R:R:Q},'
SUBST_SED.autovars+=	-e 's,@MINOR_VERSION@,${PKGVERSION:R:E:Q},'
SUBST_SED.autovars+=	-e 's,@PYTHON@,${PYTHONBIN:Q},'
SUBST_SED.autovars+=	-e 's,@DATADIR@,${PREFIX}/share,'

REPLACE_PYTHON+=	gdbus-codegen.in

.include "../../devel/meson/build.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
