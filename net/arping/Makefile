# $NetBSD: Makefile,v 1.34 2026/10/24 19:43:42 drixter Exp $

DISTNAME=	arping-2.29
CATEGORIES=	net
MASTER_SITES=	https://www.habets.pp.se/synscan/files/

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://www.habets.pp.se/synscan/programs_arping.html
COMMENT=	ARP-level ping utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
