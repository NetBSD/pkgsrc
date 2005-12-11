# $NetBSD: Makefile,v 1.13 2005/12/11 09:40:38 wiz Exp $
#

DISTNAME=	xmms-nebulus-0.6.0
PKGREVISION=	3
CATEGORIES=	xmms audio
MASTER_SITES=	http://nebulus.tuxfamily.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://nebulus.tuxfamily.org/
COMMENT=	Xmms plugin that uses OpenGL

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
