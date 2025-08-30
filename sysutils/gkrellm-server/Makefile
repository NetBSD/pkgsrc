# $NetBSD: Makefile,v 1.36 2025/08/30 08:24:21 pho Exp $

.include "../../sysutils/gkrellm/Makefile.common"

GKRELLM_PKGBASE=	gkrellm-server
COMMENT=		Monitoring daemon remotely accessible by a GKrellM client
DEPENDS+=		gkrellm-share-${GKRELLM_VERSION}:../../sysutils/gkrellm-share

USE_TOOLS+=		pkg-config
PTHREAD_OPTS+=		require
RCD_SCRIPTS=		gkrellmd
EGDIR=			${PREFIX}/share/examples/gkrellm-server
CONF_FILES=		${EGDIR}/gkrellmd.conf ${PKG_SYSCONFDIR}/gkrellmd.conf

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly"
SPECIAL_PERMS+=		${PREFIX}/bin/gkrellmd ${REAL_ROOT_USER} kmem 2555
.endif

SUBST_CLASSES+=		gkprefix
SUBST_STAGE.gkprefix=	pre-configure
SUBST_FILES.gkprefix=	server/gkrellmd.h
SUBST_SED.gkprefix+=	-e '/GKRELLMD_LOCAL_ETC/d'
SUBST_SED.gkprefix+=	-e '/GKRELLMD_SYS_ETC/{s!/etc!${PKG_SYSCONFDIR}!;}'

BUILD_DIRS=		server
BUILD_TARGET=		${GKRELLM_PER_PLATFORM_TARGET}
.if !empty(PKG_OPTIONS:Mnls)
BUILD_MAKE_FLAGS+=	LOCALEDIR=${PREFIX}/${PKGLOCALEDIR}/locale
.endif

INSTALL_MAKE_FLAGS+=	CFGDIR=${DESTDIR}${EGDIR}
INSTALL_MAKE_FLAGS+=	SINSTALLDIR=${DESTDIR}${PREFIX}/sbin
INSTALL_MAKE_FLAGS+=	SMANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
INSTALL_TARGET=		install_bin install_inc install_man install_cfg

# include/gkrellm2/log.h conflicts with sysutils/gkrellm because the latter
# also installs exactly the same file. Removing it means that one cannot
# build a gkrellm plugin with only the server installed, but can we do
# anything better than this?
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/include/gkrellm2/log.h

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
