# $NetBSD: Makefile,v 1.3 2003/07/13 13:50:37 wiz Exp $
#

DISTNAME=	xmms-nebulus-0.3.0
PKGREVISION=	2
CATEGORIES=	xmms audio
MASTER_SITES=	http://nebulus.tuxfamily.org/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://nebulus.tuxfamily.org/
COMMENT=	Xmms plugin that uses OpenGL

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../audio/xmms/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
