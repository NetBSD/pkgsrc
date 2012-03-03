# $NetBSD: Makefile,v 1.18 2012/03/03 00:14:24 wiz Exp $

.include "../../chat/xchat/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-python-/}
PKGREVISION=		3
OWNER=			tron@NetBSD.org

COMMENT=		Python scripting plugin for XChat

DEPENDS+=		xchat>=2.0.0:../../chat/xchat

BUILD_DIRS?=		plugins/python

CONFIGURE_ARGS+=	--disable-gtkfe
CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		ac_cv_path_pythonpath=${PYTHONBIN:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
SUBST_CLASSES+=		libutil
SUBST_STAGE.libutil=	pre-configure
SUBST_FILES.libutil=	configure
SUBST_SED.libutil=	-e 's/ -lutil//g'
.endif

.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
