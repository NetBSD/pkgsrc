# $NetBSD: Makefile,v 1.22 2005/01/28 23:35:59 adrianp Exp $
# $OpenBSD: Makefile,v 1.13 2000/06/19 18:38:55 dugsong Exp $

DISTNAME=	dsniff-2.3
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES+=	http://monkey.org/~dugsong/dsniff/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://monkey.org/~dugsong/dsniff/
COMMENT=	Password sniffer

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_X11=	yes

BUILDLINK_DEPENDS.libnet+=	libnet<=1.0.1b

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libnids/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
