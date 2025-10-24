# $NetBSD: Makefile,v 1.54 2025/10/24 20:05:04 js Exp $

DISTNAME=	objfw-1.4.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://objfw.nil.im/downloads/

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://objfw.nil.im/
COMMENT=	Portable, lightweight framework for the Objective-C language
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=		yes
USE_LANGUAGES=		objc
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	OBJCFLAGS=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	LDFLAGS=${LDFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	PLIST
PLIST_VARS+=	ddp ipx ofgctester sctp

.if ${OPSYS} == "Darwin"
PLIST_SRC+=		PLIST.bridge
PLIST_SRC+=		PLIST.framework
PLIST.ofgctester=	yes
.else
PLIST_SRC+=		PLIST.runtime
.endif

.if ${OPSYS} == "NetBSD"
PLIST.ddp=		yes
PLIST.sctp=		yes
.endif

.if ${OPSYS} == "FreeBSD"
PLIST.sctp=		yes
.endif

.if ${OPSYS} == "Linux"
PLIST.ddp=		yes
PLIST.ipx=		yes
PLIST.ofgctester=	yes
PLIST.sctp=		yes
.endif

do-test:
	${RUN} cd ${WRKSRC} && ${MAKE} check

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
