# $NetBSD: Makefile,v 1.19 2016/04/11 19:01:46 ryoon Exp $
#

PKGNAME=	ObjectiveLib-1.0.0
DISTNAME=	objectivelib-1.0.0
PKGREVISION=	9
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=objectivelib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://objectivelib.sourceforge.net/
COMMENT=	Object containers and generic algorithms for Objective-C
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	destdir
MAKE_JOBS_SAFE=		no
USE_LANGUAGES=		objc

WRKSRC=			${WRKDIR}/objectivelib

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
