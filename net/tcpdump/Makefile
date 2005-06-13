# $NetBSD: Makefile,v 1.13.2.2 2005/06/13 05:31:49 snj Exp $

DISTNAME=		tcpdump-3.8.3
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tech-pkg@NetBSD.org
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
