# $NetBSD: Makefile,v 1.45 2025/04/17 21:50:30 wiz Exp $

DISTNAME=	objfw-1.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://objfw.nil.im/downloads/

PATCHFILES=		2d297b2d3702d24662819016b57f0a67d902990d.patch
PATCH_SITES=		https://github.com/ObjFW/ObjFW/commit/
PATCH_DIST_STRIP=	-p1

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

.if ${OPSYS} != "Darwin"
TOOL_DEPENDS+=		clang>=3.2:../../lang/clang
.endif

PLIST_SRC=	PLIST

.if ${OPSYS} == "Darwin"
PLIST_SRC+=	PLIST.bridge
PLIST_SRC+=	PLIST.framework
.else
PLIST_SRC+=	PLIST.runtime
.endif

.if ${OPSYS} == "NetBSD"
PLIST_SRC+=	PLIST.ddp
PLIST_SRC+=	PLIST.sctp
.endif

.if ${OPSYS} == "FreeBSD"
PLIST_SRC+=	PLIST.sctp
.endif

.if ${OPSYS} == "Linux"
PLIST_SRC+=	PLIST.ddp
PLIST_SRC+=	PLIST.ipx
PLIST_SRC+=	PLIST.sctp
.endif

do-test:
	${RUN} cd ${WRKSRC} && ${MAKE} check

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
