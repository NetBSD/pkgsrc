# $NetBSD: Makefile,v 1.12 2005/12/29 06:21:59 jlam Exp $

DISTNAME=		howl-0.9.10
CATEGORIES=		net
MASTER_SITES=		http://www.porchdogsoft.com/download/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.porchdogsoft.com/products/howl/
COMMENT=		Zeroconf (Rendezvous) implementation

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PTHREAD_AUTO_VARS=	yes

RCD_SCRIPTS=		howl
PKG_GROUPS+=		howl
PKG_USERS+=		howl:howl::Zeroconf\ user

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
