# $NetBSD: Makefile,v 1.1.1.1 2002/09/27 10:44:47 rh Exp $
#

DISTNAME=	gnustep-objc-1.2.2
CATEGORIES=	devel gnustep
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/libs/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Objective-C runtime

NO_CONFIGURE=	YES

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

.include "../../devel/gnustep-make/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
