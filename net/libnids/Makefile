# $NetBSD: Makefile,v 1.9 2003/10/10 08:44:44 cube Exp $
# $FreeBSD: ports/net/libnids/Makefile,v 1.5 2000/04/24 07:42:58 kris Exp $
#

DISTNAME=	libnids-1.17
CATEGORIES=	net security
MASTER_SITES=	http://www.avet.com.pl/~nergal/libnids/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.avet.com.pl/~nergal/libnids/
COMMENT=	Network monitoring library with TCP/IP reassembly

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

BUILDLINK_DEPMETHOD.libnet=	build
BUILDLINK_DEPMETHOD.libpcap=	build

.include "../../devel/libnet/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
