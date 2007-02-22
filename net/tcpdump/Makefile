# $NetBSD: Makefile,v 1.23 2007/02/22 19:27:00 wiz Exp $

DISTNAME=		tcpdump-3.9.4
CATEGORIES=		net
MASTER_SITES=	http://www.tcpdump.org/release/

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
