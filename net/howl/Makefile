# $NetBSD: Makefile,v 1.2 2004/08/16 23:21:56 schmonz Exp $

DISTNAME=		howl-0.9.5
CATEGORIES=		net
MASTER_SITES=		http://www.porchdogsoft.com/download/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.porchdogsoft.com/products/howl/
COMMENT=		Zeroconf (Rendezvous) implementation

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
