# $NetBSD: Makefile,v 1.8 2005/06/17 03:50:23 jlam Exp $
#

DISTNAME=		arping-2.05
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://www.habets.pp.se/synscan/programs.php?prog=arping
COMMENT=		ARP-level ping utility

NO_CONFIGURE=		yes

LIBS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
BUILD_FOR=		openbsd
.elif ${OPSYS} == "Linux"
BUILD_FOR=		linux
.elif ${OPSYS} == "FreeBSD"
BUILD_FOR=		freebsd
.elif ${OPSYS} == "SunOS"
BUILD_FOR=		solaris
.elif ${OPSYS} == "Darwin"
BUILD_FOR=		macosx
.endif

.if !empty(PKG_OPTIONS:Marping1)
BUILD_TARGET=		arping1 ${BUILD_FOR}
.endif

INSTALLATION_DIRS=	bin man/man8

.include "../../net/libpcap/buildlink3.mk"

do-install:
	${INSTALL_MAN} ${WRKSRC}/arping.8 ${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/arping ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
