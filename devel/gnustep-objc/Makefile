# $NetBSD: Makefile,v 1.9 2005/04/11 21:45:24 tv Exp $
#

DISTNAME=	gnustep-objc-1.3.0
CATEGORIES=	devel gnustep
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/libs/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Objective-C runtime

USE_GNU_TOOLS+=		make
MAKEFILE=		GNUmakefile
NO_CONFIGURE=		YES

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
