# $NetBSD: Makefile,v 1.122 2024/05/29 16:34:24 adam Exp $
.include "Makefile.common"

PKGREVISION=		59

GKRELLM_PKGBASE=	gkrellm
WRKSRC=			${GKRELLM_SRCDIR}

COMMENT=		GTK2 based system monitor

DEPENDS+=		gkrellm-share-${GKRELLM_VERSION}:../../sysutils/gkrellm-share

USE_TOOLS+=		pkg-config

.include "../../mk/bsd.prefs.mk"

# NetBSD 3.99.1 and above don't have to be installed setgid.
.if (${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly" || \
    (${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 039900))
SPECIAL_PERMS+=		${PREFIX}/bin/gkrellm ${BINOWN} kmem 2555
.endif

NOT_FOR_PLATFORM=	IRIX-*-*

.include "options.mk"

MAKE_ENV+=		MODULES=src LINK_FLAGS=${EXPORT_SYMBOLS_LDFLAGS:Q}
MAKE_ENV+=		SSL_TYPE=${GKRELLM_SSL_TYPE:Q}
MAKE_ENV+=		PKG_INCLUDE=-I${BUILDLINK_PREFIX.${GKRELLM_SSL_TYPE}}/include
MAKE_ENV+=		PKG_LIBS="-L${BUILDLINK_PREFIX.${GKRELLM_SSL_TYPE}}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.${GKRELLM_SSL_TYPE}}/lib"
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_ENV+=		SMANDIR=${PREFIX}/${PKGMANDIR}/man8
MAKE_FLAGS+=		BINOWNER=${BINOWN} BINGROUP=${BINGRP}
INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	SMANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

# Fix PR pkg/40047, Thanks to Ondrej Tuma
.if ${OBJECT_FMT} == "ELF" && ${OPSYS} != "SunOS"
LDFLAGS+=	-Wl,-export-dynamic
.endif

SUBST_CLASSES+=		gkprefix
SUBST_STAGE.gkprefix=	pre-configure
SUBST_FILES.gkprefix=	src/gkrellm.h
SUBST_SED.gkprefix=	-e '/SYSTEM_/{s!/usr!${PREFIX}!;}'

REQD_DIRS=	lib/gkrellm2/plugins lib/gkrellm2 include/gkrellm2

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
