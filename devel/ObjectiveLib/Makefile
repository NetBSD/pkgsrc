# $NetBSD: Makefile,v 1.6 2006/07/21 06:33:48 rillig Exp $
#

DISTNAME=	ObjectiveLib-0.9
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=objectivelib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://objectivelib.sourceforge.net/
COMMENT=	Object containers and generic algorithms for Objective-C

USE_LANGUAGES=	c objc

WRKSRC=		${WRKDIR}

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
