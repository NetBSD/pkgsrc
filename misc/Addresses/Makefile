# $NetBSD: Makefile,v 1.3 2004/09/24 01:56:54 rh Exp $
#

DISTNAME=		Addresses-0.4.5
PKGREVISION=		2
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
