# $NetBSD: Makefile,v 1.4 2023/08/29 16:13:57 js Exp $

DISTNAME=	objfw-1.0
CATEGORIES=	devel
MASTER_SITES=	https://objfw.nil.im/downloads/

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://objfw.nil.im/
COMMENT=	Portable, lightweight framework for the Objective-C language
LICENSE=	qpl-v1.0 OR gnu-gpl-v2 OR gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LANGUAGES=		objc
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	OBJCFLAGS=${CFLAGS:M*:Q} LDFLAGS=${LDFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	PLIST

.if ${OPSYS} == "Darwin"
PLIST_SRC+=	${PKGDIR}/PLIST.bridge
PLIST_SRC+=	${PKGDIR}/PLIST.framework
.else
PLIST_SRC+=	${PKGDIR}/PLIST.runtime
.endif

.include "../../mk/bsd.pkg.mk"
