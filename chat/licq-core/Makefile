# $NetBSD: Makefile,v 1.7 2005/04/11 21:45:04 tv Exp $
#

DISTNAME=	licq-1.2.6
PKGNAME=	${DISTNAME:C/-/-core-/}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	ICQ client with plugin support

USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
