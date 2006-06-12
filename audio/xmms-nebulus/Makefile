# $NetBSD: Makefile,v 1.16 2006/06/12 16:28:05 wiz Exp $
#

DISTNAME=	xmms-nebulus-0.6.0
PKGREVISION=	5
CATEGORIES=	xmms audio
MASTER_SITES=	http://nebulus.tuxfamily.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nebulus.tuxfamily.org/
COMMENT=	Xmms plugin that uses OpenGL

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
