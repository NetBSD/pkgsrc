# $NetBSD: Makefile,v 1.7 2004/02/14 17:21:34 jlam Exp $
#

DISTNAME=	xmms-nebulus-0.6.0
CATEGORIES=	xmms audio
MASTER_SITES=	http://nebulus.tuxfamily.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://nebulus.tuxfamily.org/
COMMENT=	Xmms plugin that uses OpenGL

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../audio/xmms/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
