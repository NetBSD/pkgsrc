# $NetBSD: Makefile,v 1.19 2004/04/25 04:25:23 snj Exp $
# $OpenBSD: Makefile,v 1.13 2000/06/19 18:38:55 dugsong Exp $

DISTNAME=	dsniff-2.3
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES+=	http://monkey.org/~dugsong/dsniff/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://monkey.org/~dugsong/dsniff/
COMMENT=	Password sniffer

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_X11=	yes
NO_EXPORT_CPP=	yes

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libnids/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
