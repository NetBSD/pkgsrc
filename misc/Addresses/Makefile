# $NetBSD: Makefile,v 1.1.1.1 2004/04/02 07:40:56 rh Exp $
#

DISTNAME=		Addresses-0.4.5
CATEGORIES=		misc gnustep
MASTER_SITES=		http://giesler.biz/bjoern/downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://giesler.biz/bjoern/en/sw_addr.html
COMMENT=		Address book for GNUstep

NO_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
MAKEFILE=		GNUmakefile
MAKE_ENV+=		Addresses_OBJCFLAGS=-I..

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
