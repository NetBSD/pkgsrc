# $NetBSD: Makefile,v 1.13 2006/05/28 00:26:26 rh Exp $
#

DISTNAME=	gnustep-objc-1.3.0
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=libs/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Objective-C runtime

USE_LANGUAGES=	c objc
USE_TOOLS+=	gmake
MAKEFILE=	GNUmakefile
NO_CONFIGURE=	YES

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
