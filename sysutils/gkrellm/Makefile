# $NetBSD: Makefile,v 1.136 2026/02/06 10:05:53 wiz Exp $

PKGREVISION= 5
.include "Makefile.common"

GKRELLM_PKGBASE=	gkrellm
COMMENT=		GTK2 based system monitor
DEPENDS+=		gkrellm-share-${GKRELLM_VERSION}:../../sysutils/gkrellm-share

USE_TOOLS+=		pkg-config

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly"
SPECIAL_PERMS+=		${PREFIX}/bin/gkrellm ${BINOWN} kmem 2555
.endif

SUBST_CLASSES+=		gkprefix
SUBST_STAGE.gkprefix=	pre-configure
SUBST_FILES.gkprefix=	src/gkrellm.h
SUBST_SED.gkprefix+=	-e '/LOCAL_[A-Z][A-Z]*_DIR/d'
SUBST_SED.gkprefix+=	-e '/SYSTEM_[A-Z][A-Z]*_DIR/{s!/usr!${PREFIX}!;}'

BUILD_DIRS=		src
BUILD_TARGET=		${GKRELLM_PER_PLATFORM_TARGET}
.if !empty(PKG_OPTIONS:Mnls)
BUILD_MAKE_FLAGS+=	LOCALEDIR=${PREFIX}/${PKGLOCALEDIR}/locale
.endif

MAKE_ENV+=		MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

REQD_DIRS=		lib/gkrellm2/plugins lib/gkrellm2/themes

# Generate and install gkrellm.pc
post-build:
	${RUN}cd ${WRKSRC} && \
		${BUILD_MAKE_CMD} gkrellm.pc

INSTALL_MAKE_CMD= \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS}
post-install:
	${RUN}cd ${WRKSRC} && \
		${INSTALL_MAKE_CMD} install_gkrellm.pc

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
