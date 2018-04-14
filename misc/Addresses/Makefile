# $NetBSD: Makefile,v 1.39 2018/04/14 07:33:57 adam Exp $
#

DISTNAME=		Addresses-0.4.8
PKGREVISION=		13
CATEGORIES=		misc gnustep
MASTER_SITES=		http://savannah.nongnu.org/download/gap/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://giesler.biz/bjoern/en/sw_addr.html
COMMENT=		Address book for GNUstep
LICENSE=		gnu-lgpl-v2

USE_LANGUAGES=		objc

NO_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
MAKE_ENV+=		Addresses_OBJCFLAGS=-I..
MAKE_FILE=		GNUmakefile

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
