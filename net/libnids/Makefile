# $NetBSD: Makefile,v 1.17 2005/02/05 16:11:47 adrianp Exp $
# $FreeBSD: ports/net/libnids/Makefile,v 1.5 2000/04/24 07:42:58 kris Exp $
#

DISTNAME=	libnids-1.18
PKGREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libnids/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://libnids.sourceforge.net/
COMMENT=	Network monitoring library with TCP/IP reassembly

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

BUILDLINK_DEPMETHOD.libnet=	build
BUILDLINK_DEPMETHOD.libpcap=	build
BUILDLINK_DEPENDS.libnet+=	libnet-1.0.*

.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
