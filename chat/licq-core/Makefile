# $NetBSD: Makefile,v 1.6 2005/02/21 20:26:09 hubertf Exp $
#

DISTNAME=	licq-1.2.6
PKGNAME=	${DISTNAME:C/-/-core-/}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	ICQ client with plugin support

USE_BUILDLINK3=	YES
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
