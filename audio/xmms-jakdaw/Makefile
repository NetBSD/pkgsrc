# $NetBSD: Makefile,v 1.7 2004/03/12 01:11:39 snj Exp $

DISTNAME=	jakdaw-0.0.4
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	audio xmms
MASTER_SITES=	http://www.jakdaw.ucam.org/xmms/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.jakdaw.ucam.org/xmms
COMMENT=	Very customizable XMMS plugin with nice effects

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
