# $NetBSD: Makefile,v 1.6 2005/01/08 06:24:41 schmonz Exp $

DISTNAME=		howl-0.9.8
CATEGORIES=		net
MASTER_SITES=		http://www.porchdogsoft.com/download/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.porchdogsoft.com/products/howl/
COMMENT=		Zeroconf (Rendezvous) implementation

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
PTHREAD_AUTO_VARS=	yes

RCD_SCRIPTS=		howl
PKG_GROUPS+=		howl
PKG_USERS+=		howl:howl::Zeroconf\\ user

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
