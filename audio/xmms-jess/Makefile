# $NetBSD: Makefile,v 1.9 2004/03/12 01:15:47 snj Exp $
#

DISTNAME=	JESS-2.9.1
PKGNAME=	xmms-jess-2.9.1
PKGREVISION=	3
CATEGORIES=	xmms audio
MASTER_SITES=	http://arquier.free.fr/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://arquier.free.fr/
COMMENT=	XMMS plugin with Blur, image distortion, and others

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
