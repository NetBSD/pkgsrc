# $NetBSD: Makefile,v 1.17 2003/10/28 16:59:14 cube Exp $
# $OpenBSD: Makefile,v 1.13 2000/06/19 18:38:55 dugsong Exp $

DISTNAME=	dsniff-2.3
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES+=	http://monkey.org/~dugsong/dsniff/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://monkey.org/~dugsong/dsniff/
COMMENT=	Password sniffer

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_X11=	yes

.include "../../net/libpcap/buildlink2.mk"
.include "../../devel/libnet/buildlink2.mk"
.include "../../net/libnids/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
