# $NetBSD: Makefile,v 1.52 2025/10/05 02:46:54 js Exp $

DISTNAME=	objfw-1.4.1
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

.if ${MACHINE_ARCH} == "alpha" || \
	${MACHINE_ARCH} == "coldfire" || \
	${MACHINE_ARCH} == "hppa" || \
	${MACHINE_ARCH} == "ia64" || \
	${MACHINE_ARCH} == "m68k" || \
	${MACHINE_ARCH} == "or1k" || \
	${MACHINE_ARCH} == "sh3eb" || \
	${MACHINE_ARCH} == "sh3el" || \
	${MACHINE_ARCH} == "vax"
# Clang does not support these architectures, so build with GCC, with the
# caveat that GCC doesn't support all features.
.elif ${OPSYS} == "Darwin"
# Darwin always has good Objective-C support with the system compiler.
.else
CONFIGURE_ARGS+=	OBJC=clang	# Clang has much better ObjC support
TOOL_DEPENDS+=		clang>=3.2:../../lang/clang
PKGSRC_COMPILER=	clang
.endif

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
