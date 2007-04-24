# $NetBSD: Makefile,v 1.24 2007/04/24 12:31:47 ghen Exp $

DISTNAME=		tcpdump-3.9.5
CATEGORIES=		net
MASTER_SITES=		http://www.tcpdump.org/release/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		Network monitoring tool

GNU_CONFIGURE=		YES

.include "options.mk"

# not strictly needed
BUILDLINK_API_DEPENDS.libpcap+= libpcap>=0.9.3
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
