# $NetBSD: Makefile,v 1.9 2006/11/02 07:07:13 jdolecek Exp $
#

DISTNAME=	licq-1.2.6
PKGREVISION=	1
PKGNAME=	${DISTNAME:C/-/-core-/}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	ICQ client with plugin support

USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
