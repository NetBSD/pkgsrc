# $NetBSD: Makefile,v 1.1.1.1 2003/02/14 23:56:39 hubertf Exp $
#

DISTNAME=	jakdaw-0.0.4
PKGNAME=	xmms-${DISTNAME}
CATEGORIES=	audio xmms
MASTER_SITES=	http://www.jakdaw.ucam.org/xmms/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.jakdaw.ucam.org/xmms
COMMENT=	Very customizable XMMS plugin with nice effects

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/libtool/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
