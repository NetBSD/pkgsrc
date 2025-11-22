# $NetBSD: Makefile,v 1.33 2025/11/22 17:27:00 wiz Exp $

DISTNAME=	arping-2.21
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://www.habets.pp.se/synscan/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.habets.pp.se/synscan/programs_arping.html
COMMENT=	ARP-level ping utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
