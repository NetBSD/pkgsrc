# $NetBSD: Makefile,v 1.10 2003/10/28 16:57:00 cube Exp $
# $FreeBSD: ports/net/libnids/Makefile,v 1.5 2000/04/24 07:42:58 kris Exp $
#

DISTNAME=	libnids-1.18
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libnids/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://libnids.sourceforge.net/
COMMENT=	Network monitoring library with TCP/IP reassembly

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

BUILDLINK_DEPMETHOD.libnet=	build
BUILDLINK_DEPMETHOD.libpcap=	build

.include "../../devel/libnet/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
