# $NetBSD: Makefile,v 1.48 2026/11/11 11:52:26 wiz Exp $

DISTNAME=	objectivelib-1.0.0
PKGNAME=	ObjectiveLib-1.0.0
PKGREVISION=	34
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=objectivelib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://objectivelib.sourceforge.net/
COMMENT=	Object containers and generic algorithms for Objective-C
LICENSE=	gnu-lgpl-v2.1

MAKE_JOBS_SAFE=		no
USE_LANGUAGES=		objc

WRKSRC=			${WRKDIR}/objectivelib

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
