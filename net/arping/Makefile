# $NetBSD: Makefile,v 1.25 2016/02/09 12:00:19 mef Exp $

DISTNAME=	arping-2.16
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
