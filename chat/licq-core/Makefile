# $NetBSD: Makefile,v 1.3 2003/07/17 21:26:00 grant Exp $
#

DISTNAME=	licq-1.2.6
PKGNAME=	${DISTNAME:C/-/-core-/}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	ICQ client with plugin support

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
