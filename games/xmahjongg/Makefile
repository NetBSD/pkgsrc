# $NetBSD: Makefile,v 1.32 2023/07/17 22:00:23 nia Exp $
#

DISTNAME=	xmahjongg-3.7
PKGNAME=	${DISTNAME}0
CATEGORIES=	games x11
MASTER_SITES=	http://www.lcdf.org/~eddietwo/xmahjongg/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://www.lcdf.org/~eddietwo/xmahjongg/
COMMENT=	The Chinese game of Mah Jongg for X11

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++03

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
