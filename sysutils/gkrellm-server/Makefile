# $NetBSD: Makefile,v 1.23 2007/06/15 18:15:21 jlam Exp $

.include "../../sysutils/gkrellm/Makefile.common"

GKRELLM_PKGBASE=	gkrellm-server
COMMENT=		Monitoring daemon remotely accessible by a GKrellM client
DEPENDS+=		gkrellm-share-${GKRELLM_VERSION}:../../sysutils/gkrellm-share

USE_TOOLS+=		pkg-config
PTHREAD_OPTS+=		require
RCD_SCRIPTS=		gkrellmd
CONF_FILES=		${PREFIX:Q}/share/examples/gkrellm-server/gkrellmd.conf ${PREFIX:Q}/etc/gkrellmd.conf

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly")
SPECIAL_PERMS+=		${PREFIX:Q}/bin/gkrellmd ${BINOWN} kmem 2555
.endif

NOT_FOR_PLATFORM=	IRIX-*-*

MAKE_ENV+=		MODULES=server

PKG_OPTIONS_VAR=	PKG_OPTIONS.gkrellm-server
PKG_SUPPORTED_OPTIONS=	glib1

.include "../../mk/bsd.options.mk"

SUBST_CLASSES+=		gkprefix
SUBST_STAGE.gkprefix=	post-patch
SUBST_FILES.gkprefix=	server/gkrellmd.h
SUBST_SED.gkprefix=	-e '/GKRELLMD_SYS_ETC/{s!/etc!${PREFIX}&!;}'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/examples/gkrellm-server
	${INSTALL_DATA} ${WRKSRC:Q}/server/gkrellmd.conf ${PREFIX:Q}/share/examples/gkrellm-server

.if !empty(PKG_OPTIONS:Mglib1)
MAKE_ENV+=		USE_GLIB12=yes
.include "../../devel/glib/buildlink3.mk"
.else
.include "../../devel/glib2/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
