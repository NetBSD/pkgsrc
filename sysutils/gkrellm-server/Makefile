# $NetBSD: Makefile,v 1.16 2005/12/05 20:51:00 rillig Exp $
.include "../../sysutils/gkrellm/Makefile.common"

GKRELLM_PKGBASE=	gkrellm-server
COMMENT=		Monitoring daemon remotely accessible by a GKrellM client
DEPENDS+=		gkrellm-share-${GKRELLM_VERSION}:../../sysutils/gkrellm-share

USE_TOOLS+=		pkg-config
USE_PKGINSTALL=		YES
PTHREAD_OPTS+=		require
RCD_SCRIPTS=		gkrellmd
CONF_FILES=		${PREFIX}/share/examples/gkrellm-server/gkrellmd.conf ${PREFIX}/etc/gkrellmd.conf

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "NetBSD")
SPECIAL_PERMS+=         ${PREFIX}/bin/gkrellmd ${ROOT_USER} kmem 2711
.endif

NOT_FOR_PLATFORM=	IRIX-*-*

MAKE_ENV+=		MODULES=server

PKG_OPTIONS_VAR=	PKG_OPTIONS.gkrellm-server
PKG_SUPPORTED_OPTIONS=	glib1
PKG_DEFAULTS_OPTIONS?=	# empty

.include "../../mk/bsd.options.mk"

SUBST_STAGE.gkprefix=	post-patch
SUBST_FILES.gkprefix=	server/gkrellmd.h
SUBST_SED.gkprefix=	-e '/GKRELLMD_SYS_ETC/{s!/etc!${PREFIX}&!;}'
SUBST_CLASSES+=		gkprefix

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gkrellm-server
	${INSTALL_DATA} ${WRKSRC}/server/gkrellmd.conf ${PREFIX}/share/examples/gkrellm-server

.if !empty(PKG_OPTIONS:Mglib1)
MAKE_ENV+=		USE_GLIB12=yes
.include "../../devel/glib/buildlink3.mk"
.else
.include "../../devel/glib2/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
