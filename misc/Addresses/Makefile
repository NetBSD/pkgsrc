# $NetBSD: Makefile,v 1.5 2004/11/17 04:28:59 rh Exp $
#

DISTNAME=		Addresses-0.4.6
CATEGORIES=		misc gnustep
MASTER_SITES=		http://giesler.biz/bjoern/downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://giesler.biz/bjoern/en/sw_addr.html
COMMENT=		Address book for GNUstep

USE_BUILDLINK3=		yes
USE_X11=		yes
NO_CONFIGURE=		yes
MAKE_ENV+=		Addresses_OBJCFLAGS=-I..

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
