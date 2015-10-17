# $NetBSD: Makefile,v 1.39 2015/10/17 10:08:22 adam Exp $

DISTNAME=	tcpdump-4.7.4
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcpdump.org/
COMMENT=	Network monitoring tool
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes

.include "options.mk"

.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
