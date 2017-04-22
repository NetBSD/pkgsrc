# $NetBSD: Makefile,v 1.22 2017/04/22 21:03:29 adam Exp $
#

PKGNAME=	ObjectiveLib-1.0.0
DISTNAME=	objectivelib-1.0.0
PKGREVISION=	11
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
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
