# $NetBSD: Makefile,v 1.32 2013/02/06 19:31:01 jperkin Exp $

DISTNAME=	tcpdump-4.1.1
PKGREVISION=	1
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
