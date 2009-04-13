# $NetBSD: Makefile,v 1.16 2009/04/13 12:12:44 rh Exp $
#

DISTNAME=	gnustep-objc-1.6.0
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=libs/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Objective-C runtime

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=		gnu-gpl-v3

USE_LANGUAGES=	objc
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile
MAKE_ENV+=	ADDITIONAL_LDFLAGS=-lpthread
NO_CONFIGURE=	YES

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
