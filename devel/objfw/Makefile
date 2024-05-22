# $NetBSD: Makefile,v 1.29 2024/05/22 20:29:38 js Exp $

DISTNAME=	objfw-1.1.4
CATEGORIES=	devel
MASTER_SITES=	https://objfw.nil.im/downloads/

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://objfw.nil.im/
COMMENT=	Portable, lightweight framework for the Objective-C language
LICENSE=	gnu-lgpl-v3

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

do-test:
	${RUN} cd ${WRKSRC} && ${MAKE} check

.include "options.mk"

.if ${OPSYS} != "Darwin"
.include "../../lang/clang/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
