# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:15 tv Exp $
.include "../../sysutils/gkrellm/Makefile.common"

PKGREVISION=		# empty1

GKRELLM_PKGBASE=	gkrellm-server
COMMENT=		Monitoring daemon remotely accessible by a GKrellM client
DEPENDS+=		gkrellm-share-${GKRELLM_VERSION}:../../sysutils/gkrellm-share

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
PTHREAD_OPTS=		require
RCD_SCRIPTS=		gkrellmd
CONF_FILES=		${PREFIX}/share/examples/gkrellm-server/gkrellmd.conf ${PREFIX}/etc/gkrellmd.conf

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "NetBSD")
SPECIAL_PERMS+=         ${PREFIX}/bin/gkrellmd ${ROOT_USER} kmem 2711
.endif

NOT_FOR_PLATFORM=	IRIX-*

MAKE_ENV+=		MODULES=server

# Define this to use glib-1.2 instead of glib-2
BUILD_DEFS+=		GKRELLMSERVER_USE_GLIB12

SUBST_STAGE.gkprefix=	post-patch
SUBST_FILES.gkprefix=	${WRKSRC}/server/gkrellmd.h
SUBST_SED.gkprefix=	-e '/GKRELLMD_SYS_ETC/{s!/etc!${PREFIX}&!;}'
SUBST_CLASSES+=		gkprefix

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gkrellm-server
	${INSTALL_DATA} ${WRKSRC}/server/gkrellmd.conf ${PREFIX}/share/examples/gkrellm-server

.if defined(GKRELLMSERVER_USE_GLIB12)
MAKE_ENV+=		USE_GLIB12=yes
.include "../../devel/glib/buildlink3.mk"
.else
.include "../../devel/glib2/buildlink3.mk"
.endif
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
