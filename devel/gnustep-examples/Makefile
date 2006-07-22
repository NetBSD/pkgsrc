# $NetBSD: Makefile,v 1.22 2006/07/22 05:10:54 rillig Exp $
#

DISTNAME=	gnustep-examples-1.0.0
PKGREVISION=	4
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Some GUI programming examples for GNUstep

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
