# $NetBSD: Makefile,v 1.26 2008/01/18 05:08:49 tnn Exp $

DISTNAME=		tcpdump-3.9.7
PKGREVISION=		2
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
