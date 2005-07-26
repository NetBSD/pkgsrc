# $NetBSD: Makefile,v 1.5 2005/07/26 10:47:19 wiz Exp $
#

DISTNAME=		ucarp-1.0
PKGREVISION=	1
CATEGORIES=		net
MASTER_SITES=		http://www.pureftpd.org/ucarp/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ucarp.org/
COMMENT=		Common Address Redundancy Protocol (CARP) for Unix

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

# pcap_freecode with one argument only
BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.6.0

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
