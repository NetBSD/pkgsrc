# $NetBSD: Makefile,v 1.21 2009/10/06 15:05:28 joerg Exp $
#

DISTNAME=	gnustep-objc-1.6.0
PKGREVISION=	2
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=libs/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Objective-C runtime
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=		user-destdir

MAKE_JOBS_SAFE=	no

USE_LANGUAGES=			objc
USE_TOOLS+=			gmake
MAKE_FILE=			GNUmakefile
MAKE_ENV+=			ADDITIONAL_LDFLAGS=-lpthread
GNUSTEP_OVERRIDE_INSTALL=	YES
NO_CONFIGURE=			YES

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
