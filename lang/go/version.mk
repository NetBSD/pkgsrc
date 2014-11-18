# $NetBSD: version.mk,v 1.1 2014/11/18 20:39:11 bsiegert Exp $

.include "../../mk/bsd.prefs.mk"

GO_VERSION=	1.3.3

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-evbarm
NOT_FOR_PLATFORM=	SunOS-*-i386
.if ${MACHINE_ARCH} == "i386"
GOARCH=		386
GO_COMPILER=	8
.elif ${MACHINE_ARCH} == "x86_64"
GOARCH=		amd64
GO_COMPILER=	6
.elif ${MACHINE_ARCH} == "evbarm"
GOARCH=		arm
GO_COMPILER=	5
.endif
PLIST_SUBST+=	GO_PLATFORM=${LOWER_OPSYS:Q}_${GOARCH:Q} GOARCH=${GOARCH:Q}
PLIST_SUBST+=	GO_COMPILER=${GO_COMPILER:Q}
