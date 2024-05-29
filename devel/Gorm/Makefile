# $NetBSD: Makefile,v 1.80 2024/05/29 16:31:56 adam Exp $

DISTNAME=	gorm-1.2.28
PKGNAME=	${DISTNAME:S/gorm/Gorm/}
PKGREVISION=	3
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Graphical user interface builder for GNUstep
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

# /usr/bin/ld: ./obj/Gorm.obj/Gorm.m.o: undefined reference to symbol '_Unwind_Resume'
# /usr/bin/ld: /usr/pkg/lib/libunwind.so.1: error adding symbols: DSO missing from command line
LDFLAGS.NetBSD+=	-L${PREFIX}/lib -lunwind
MAKE_ENV+=		ADDITIONAL_LDFLAGS=${LDFLAGS:Q}

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
