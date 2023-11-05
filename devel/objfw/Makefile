# $NetBSD: Makefile,v 1.15 2023/11/05 11:25:59 js Exp $

DISTNAME=	objfw-1.0.5
CATEGORIES=	devel
MASTER_SITES=	https://objfw.nil.im/downloads/

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://objfw.nil.im/
COMMENT=	Portable, lightweight framework for the Objective-C language
LICENSE=	qpl-v1.0 OR gnu-gpl-v2 OR gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LANGUAGES=		objc
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	OBJC=clang	# Clang has much better ObjC support
CONFIGURE_ARGS+=	OBJCFLAGS=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	LDFLAGS=${LDFLAGS:M*:Q}
PKGSRC_COMPILER=	clang

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	PLIST

.if ${OPSYS} == "Darwin"
PLIST_SRC+=	PLIST.bridge
PLIST_SRC+=	PLIST.framework
.else
PLIST_SRC+=	PLIST.runtime
.endif

.if ${OPSYS} == "NetBSD"
PLIST_SRC+=	PLIST.ddp
.endif

.if ${OPSYS} == "Linux"
PLIST_SRC+=	PLIST.ddp
PLIST_SRC+=	PLIST.ipx
.endif

.include "options.mk"

.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
