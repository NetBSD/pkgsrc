# $NetBSD: Makefile,v 1.3.2.1 2002/07/01 17:45:04 jlam Exp $

DISTNAME=		tcpdump-3.7.1
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		network monitoring tool

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

.if exists(/usr/include/netinet/ip6.h)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../net/libpcap/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
