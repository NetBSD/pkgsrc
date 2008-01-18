# $NetBSD: Makefile,v 1.18 2008/01/18 05:08:32 tnn Exp $
#

DISTNAME=		Addresses-0.4.6
PKGREVISION=		6
CATEGORIES=		misc gnustep
MASTER_SITES=		http://giesler.biz/bjoern/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://giesler.biz/bjoern/en/sw_addr.html
COMMENT=		Address book for GNUstep

USE_LANGUAGES=		objc

NO_CONFIGURE=		yes
MAKE_ENV+=		Addresses_OBJCFLAGS=-I..
MAKE_FILE=		GNUmakefile

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
