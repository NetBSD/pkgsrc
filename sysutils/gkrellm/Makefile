# $NetBSD: Makefile,v 1.33 2004/03/29 06:47:30 cube Exp $
.include "Makefile.common"

PKGREVISION=		# defined

GKRELLM_PKGBASE=	gkrellm
WRKSRC=			${GKRELLM_SRCDIR}

COMMENT=		GTK2 based system monitor

DEPENDS+=		gkrellm-share-${GKRELLM_VERSION}:../../sysutils/gkrellm-share

USE_BUILDLINK3=		YES
USE_X11=		YES
USE_PKGINSTALL=		YES

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD")
SPECIAL_PERMS+=		${PREFIX}/bin/gkrellm ${ROOT_USER} kmem 2711
.endif

NOT_FOR_PLATFORM=	IRIX-*

MAKE_ENV+=		MODULES=src LINK_FLAGS=${EXPORT_SYMBOLS_LDFLAGS}

SUBST_STAGE.gkprefix=	post-patch
SUBST_FILES.gkprefix=	${WRKSRC}/src/gkrellm.h
SUBST_SED.gkprefix=	-e '/SYSTEM_/{s!/usr!${PREFIX}!;}'
SUBST_CLASSES+=		gkprefix

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm2
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm2/plugins
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm2/themes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
