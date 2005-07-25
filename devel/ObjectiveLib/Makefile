# $NetBSD: Makefile,v 1.2 2005/07/25 00:32:44 kristerw Exp $
#

DISTNAME=	ObjectiveLib-0.9
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=objectivelib/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://objectivelib.sourceforge.net/
COMMENT=	Object containers and generic algorithms for Objective-C

WRKSRC=		${WRKDIR}

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
