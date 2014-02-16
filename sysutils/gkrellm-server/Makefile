# $NetBSD: Makefile,v 1.32 2014/02/16 00:45:28 wiedi Exp $

.include "../../sysutils/gkrellm/Makefile.common"

GKRELLM_PKGBASE=	gkrellm-server
PKGREVISION=		5
COMMENT=		Monitoring daemon remotely accessible by a GKrellM client
DEPENDS+=		gkrellm-share-${GKRELLM_VERSION}:../../sysutils/gkrellm-share

USE_TOOLS+=		pkg-config
PTHREAD_OPTS+=		require
RCD_SCRIPTS=		gkrellmd
EGDIR=			${PREFIX}/share/examples/gkrellm-server
CONF_FILES=		${EGDIR}/gkrellmd.conf ${PKG_SYSCONFDIR}/gkrellmd.conf

CFLAGS.SunOS+=		-Du_int32_t=uint32_t

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly")
SPECIAL_PERMS+=		${PREFIX:Q}/bin/gkrellmd ${REAL_ROOT_USER} kmem 2555
.endif

NOT_FOR_PLATFORM=	IRIX-*-*

MAKE_ENV+=		MODULES=server
INSTALL_MAKE_FLAGS+=	BINOWNER=${BINOWN:Q} BINGROUP=${BINGRP:Q}

PKG_OPTIONS_VAR=	PKG_OPTIONS.gkrellm-server
PKG_SUPPORTED_OPTIONS=	glib1

.include "../../mk/bsd.options.mk"

SUBST_CLASSES+=		gkprefix
SUBST_STAGE.gkprefix=	post-patch
SUBST_FILES.gkprefix=	server/gkrellmd.h
SUBST_SED.gkprefix=	-e '/GKRELLMD_SYS_ETC/{s!/etc!${PKG_SYSCONFDIR}!;}'

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX:Q}/share/examples/gkrellm-server
	${INSTALL_DATA} ${WRKSRC:Q}/server/gkrellmd.conf ${DESTDIR}${PREFIX:Q}/share/examples/gkrellm-server

.if !empty(PKG_OPTIONS:Mglib1)
MAKE_ENV+=		USE_GLIB12=yes
.include "../../devel/glib/buildlink3.mk"
.else
.include "../../devel/glib2/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
