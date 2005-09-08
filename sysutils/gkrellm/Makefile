# $NetBSD: Makefile,v 1.45 2005/09/08 13:19:56 cube Exp $
.include "Makefile.common"

PKGREVISION=		# empty1

GKRELLM_PKGBASE=	gkrellm
WRKSRC=			${GKRELLM_SRCDIR}

COMMENT=		GTK2 based system monitor

DEPENDS+=		gkrellm-share-${GKRELLM_VERSION}:../../sysutils/gkrellm-share

USE_PKGINSTALL=		YES
USE_TOOLS+=		pkg-config

.include "../../mk/bsd.prefs.mk"

# NetBSD 3.99.1 and above don't have to be installed setgid.
.if (${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || \
    (${OPSYS} == "NetBSD" && (!empty(OS_VERSION:M[123]*) && empty(OS_VERSION:M3.99.*))))
SPECIAL_PERMS+=		${PREFIX}/bin/gkrellm ${ROOT_USER} kmem 2711
.endif

NOT_FOR_PLATFORM=	IRIX-*

.include "options.mk"

MAKE_ENV+=		MODULES=src LINK_FLAGS=${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		BINOWNER=${BINOWN} BINGROUP=${BINGRP}
MAKE_ENV+=		SSL_TYPE=${GKRELLM_SSL_TYPE}
MAKE_ENV+=		PKG_INCLUDE=-I${BUILDLINK_PREFIX.${GKRELLM_SSL_TYPE}}/include
MAKE_ENV+=		PKG_LIBS="-L${BUILDLINK_PREFIX.${GKRELLM_SSL_TYPE}}/lib -Wl,-R${BUILDLINK_PREFIX.${GKRELLM_SSL_TYPE}}/lib"

SUBST_STAGE.gkprefix=	post-patch
SUBST_FILES.gkprefix=	src/gkrellm.h
SUBST_SED.gkprefix=	-e '/SYSTEM_/{s!/usr!${PREFIX}!;}'
SUBST_CLASSES+=		gkprefix

REQD_DIRS=	lib/gkrellm2/plugins lib/gkrellm2 include/gkrellm2

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
