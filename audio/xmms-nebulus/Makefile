# $NetBSD: Makefile,v 1.2 2003/05/02 11:53:53 wiz Exp $
#

DISTNAME=	xmms-nebulus-0.3.0
PKGREVISION=	1
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
