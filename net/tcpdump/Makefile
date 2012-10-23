# $NetBSD: Makefile,v 1.31 2012/10/23 17:19:12 asau Exp $

DISTNAME=	tcpdump-4.1.1
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcpdump.org/
COMMENT=	Network monitoring tool
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes

.include "options.mk"

# not strictly needed
BUILDLINK_API_DEPENDS.libpcap+= libpcap>=1.1.1
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
