# $NetBSD: Makefile,v 1.9 2004/03/26 02:27:50 wiz Exp $

DISTNAME=		tcpdump-3.7.2
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		Network monitoring tool

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

.if exists(/usr/include/netinet/ip6.h)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../net/libpcap/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
