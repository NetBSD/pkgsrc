# $NetBSD: Makefile,v 1.11 2005/02/21 20:26:09 hubertf Exp $
#

DISTNAME=	JESS-2.9.1
PKGNAME=	xmms-jess-2.9.1
PKGREVISION=	4
CATEGORIES=	xmms audio
MASTER_SITES=	http://arquier.free.fr/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://arquier.free.fr/
COMMENT=	XMMS plugin with Blur, image distortion, and others

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
