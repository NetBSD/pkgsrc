# $NetBSD: Makefile,v 1.17 2006/01/24 07:32:02 wiz Exp $
#

DISTNAME=	gnustep-examples-1.0.0
PKGREVISION=	2
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Some GUI programming examples for GNUstep

NO_CONFIGURE=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
