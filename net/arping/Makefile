# $NetBSD: Makefile,v 1.29 2020/04/10 21:25:03 schwarz Exp $

DISTNAME=	arping-2.21
CATEGORIES=	net
MASTER_SITES=	http://www.habets.pp.se/synscan/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.habets.pp.se/synscan/programs.php?prog=arping
COMMENT=	ARP-level ping utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
