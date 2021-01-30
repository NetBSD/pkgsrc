# $NetBSD: Makefile,v 1.32 2021/01/30 08:24:07 jperkin Exp $

DISTNAME=	arping-2.21
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.habets.pp.se/synscan/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.habets.pp.se/synscan/programs.php?prog=arping
COMMENT=	ARP-level ping utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
