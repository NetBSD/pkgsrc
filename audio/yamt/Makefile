# $NetBSD: Makefile,v 1.1 2002/06/23 09:23:28 kent Exp $

DISTNAME=	yamt-0.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yamt/}

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://yamt.sourceforge.net/
COMMENT=	Yet Another MP3 Tool

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
BUILD_USES_MSGFMT=	yes

.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
