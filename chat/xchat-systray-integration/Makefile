# $NetBSD: Makefile,v 1.4 2004/06/07 06:12:16 minskim Exp $

DISTNAME=	xchat-systray-integration-2.4.5-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xchat2-plugins/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://blight.altervista.org/index.php?act=Systray
COMMENT=	Systray icon plugin for X-Chat

DEPENDS=	xchat>=2.0:../../chat/xchat2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

MAKE_ENV+=	prefix=${PREFIX}

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
