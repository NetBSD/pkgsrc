# $NetBSD: Makefile,v 1.31 2021/01/30 07:51:39 mef Exp $

DISTNAME=	arping-2.21
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.habets.pp.se/synscan/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.habets.pp.se/synscan/programs.php?prog=arping
COMMENT=	ARP-level ping utility
LICENSE=	gnu-gpl-v2

# => Checking for missing run-time search paths in arping-2.21nb1
#  ERROR: /usr/pkg/lib/libnet.so.9: libnet-1.2 is not a runtime dependency
DEPENDS+=	libnet-[0-9]*:../../devel/libnet

GNU_CONFIGURE=		yes

.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
