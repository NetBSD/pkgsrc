# $NetBSD: Makefile,v 1.11 2005/12/05 20:49:54 rillig Exp $

DISTNAME=	xchat-systray-integration-2.4.5-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xchat2-plugins/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://blight.altervista.org/index.php?act=Systray
COMMENT=	Systray icon plugin for X-Chat

DEPENDS+=	xchat>=2.0:../../chat/xchat

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake pkg-config

# We build a shared object, so ensure that the object files are PIC.
CFLAGS+=	-fPIC

MAKE_ENV+=	prefix=${PREFIX:Q}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
