# $NetBSD: Makefile,v 1.2 2003/05/03 23:01:54 wiz Exp $
#

DISTNAME=	licq-1.2.6
PKGNAME=	${DISTNAME:C/-/-core-/}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	ICQ client with plugin support

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
