# $NetBSD: Makefile,v 1.47 2018/11/12 03:51:48 ryoon Exp $

DISTNAME=	xchat-systray-integration-2.4.5-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	31
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xchat2-plugins/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.patriziobassi.it/blight/index.php?act=Systray
COMMENT=	Systray icon plugin for XChat

DEPENDS+=	xchat>=2.0:../../chat/xchat

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

MAKE_ENV+=	prefix=${PREFIX} SHLIBTOOL=${SHLIBTOOL:Q}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
