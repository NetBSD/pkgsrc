# $NetBSD: Makefile,v 1.11 2004/10/03 00:18:00 tv Exp $

DISTNAME=		tcpdump-3.7.2
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		Network monitoring tool

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES

.if exists(/usr/include/netinet/ip6.h)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
