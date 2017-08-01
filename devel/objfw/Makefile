# $NetBSD: Makefile,v 1.1 2017/08/01 15:51:52 maya Exp $

DISTNAME=	objfw-0.90
CATEGORIES=	devel
MASTER_SITES=	https://heap.zone/objfw/downloads/

MAINTAINER=	js@heap.zone
HOMEPAGE=	https://heap.zone/objfw/
COMMENT=	Portable, lightweight framework for the Objective-C language
LICENSE=	qpl-v1.0 OR gnu-gpl-v2 OR gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LANGUAGES=		objc
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	OBJCFLAGS=${CFLAGS:M*:Q} LDFLAGS=${LDFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	PLIST

.if ${OPSYS} != "Darwin"
PLIST_SRC+=	${PKGDIR}/PLIST.runtime
.else
PLIST_SRC+=	${PKGDIR}/PLIST.bridge
.endif

.include "../../mk/bsd.pkg.mk"
