# $NetBSD: Makefile,v 1.5 2004/12/18 20:58:30 jlam Exp $

DISTNAME=		howl-0.9.7
# PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.porchdogsoft.com/download/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.porchdogsoft.com/products/howl/
COMMENT=		Zeroconf (Rendezvous) implementation

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PTHREAD_AUTO_VARS=	yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
