# $NetBSD: Makefile,v 1.33 2020/11/05 09:07:50 ryoon Exp $
#

PKGNAME=	ObjectiveLib-1.0.0
DISTNAME=	objectivelib-1.0.0
PKGREVISION=	20
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
