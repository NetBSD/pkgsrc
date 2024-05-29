# $NetBSD: Makefile,v 1.53 2024/05/29 16:33:29 adam Exp $

DISTNAME=		Addresses-0.4.8
PKGREVISION=		26
CATEGORIES=		misc gnustep
MASTER_SITES=		http://savannah.nongnu.org/download/gap/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gap.nongnu.org/addresses/
COMMENT=		Address book for GNUstep
LICENSE=		gnu-lgpl-v2

USE_LANGUAGES=		objc

NO_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
MAKE_ENV+=		Addresses_OBJCFLAGS=-I..
MAKE_FILE=		GNUmakefile
# /usr/bin/ld: ./obj/AddressManager.obj/Controller.m.o: undefined reference to symbol 'objc_lookup_class'
# /usr/bin/ld: /usr/pkg/lib/libobjc.so.4.6: error adding symbols: DSO missing from command line
LDFLAGS.NetBSD+=	-lunwind
MAKE_ENV+=		ADDITIONAL_LDFLAGS=${LDFLAGS:Q}

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
