# $NetBSD: Makefile,v 1.2 2003/03/01 10:17:32 jmc Exp $
#

DISTNAME=	jakdaw-0.0.4
PKGNAME=	xmms-${DISTNAME}
CATEGORIES=	audio xmms
MASTER_SITES=	http://www.jakdaw.ucam.org/xmms/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.jakdaw.ucam.org/xmms
COMMENT=	Very customizable XMMS plugin with nice effects

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/libtool/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
