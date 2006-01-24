# $NetBSD: Makefile,v 1.9 2006/01/24 07:32:22 wiz Exp $
#

DISTNAME=		Addresses-0.4.6
PKGREVISION=		2
CATEGORIES=		misc gnustep
MASTER_SITES=		http://giesler.biz/bjoern/downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://giesler.biz/bjoern/en/sw_addr.html
COMMENT=		Address book for GNUstep

NO_CONFIGURE=		yes
MAKE_ENV+=		Addresses_OBJCFLAGS=-I..

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
