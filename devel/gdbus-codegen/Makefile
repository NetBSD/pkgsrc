# $NetBSD: Makefile,v 1.20 2019/06/03 09:53:50 prlw1 Exp $

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
SUBST_SED.autovars+=	-e 's,@PYTHON@,${PYTHONBIN:Q},'
SUBST_SED.autovars+=	-e 's,@DATADIR@,${PREFIX}/share,'

REPLACE_PYTHON+=	gdbus-codegen.in

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "../../devel/py-meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
