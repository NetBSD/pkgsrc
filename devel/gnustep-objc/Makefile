# $NetBSD: Makefile,v 1.10 2005/05/22 20:07:51 jlam Exp $
#

DISTNAME=	gnustep-objc-1.3.0
CATEGORIES=	devel gnustep
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/libs/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Objective-C runtime

USE_TOOLS+=		gmake
MAKEFILE=		GNUmakefile
NO_CONFIGURE=		YES

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
