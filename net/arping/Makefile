# $NetBSD: Makefile,v 1.5 2005/01/28 23:35:59 adrianp Exp $
#

DISTNAME=		arping-2.01
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		ftp://ftp.habets.pp.se/pub/synscan/
COMMENT=		ARP-level ping utility

USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes

BUILDLINK_DEPENDS.libnet+=	libnet<=1.0.1b

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
BUILD_TARGET=		openbsd
.elif ${OPSYS} == "Linux"
BUILD_TARGET=		linux
.elif ${OPSYS} == "FreeBSD"
BUILD_TARGET=		freebsd
.elif ${OPSYS} == "SunOS"
BUILD_TARGET=		solaris
.elif ${OPSYS} == "Darwin"
BUILD_TARGET=		macosx
.endif

.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
