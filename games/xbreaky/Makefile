# $NetBSD: Makefile,v 1.4 2001/12/05 04:02:24 jlam Exp $
#

DISTNAME=	xbreaky-0.0.4
CATEGORIES=	games
MASTER_SITES=	http://xbreaky.sourceforge.net/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://xbreaky.sourceforge.net/
COMMENT=	breakout game for X11

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
