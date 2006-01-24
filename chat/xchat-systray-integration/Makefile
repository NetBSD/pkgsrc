# $NetBSD: Makefile,v 1.12 2006/01/24 07:31:58 wiz Exp $

DISTNAME=	xchat-systray-integration-2.4.5-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
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
