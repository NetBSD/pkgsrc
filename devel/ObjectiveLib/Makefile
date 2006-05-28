# $NetBSD: Makefile,v 1.5 2006/05/28 00:26:26 rh Exp $
#

DISTNAME=	ObjectiveLib-0.9
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=objectivelib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://objectivelib.sourceforge.net/
COMMENT=	Object containers and generic algorithms for Objective-C

USE_LANGUAGES=	objc

WRKSRC=		${WRKDIR}

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
